/*
 * 基于libpcap实现抓包程序案例
 * pcap_demo.c
 * Created on: Oct 27, 2016
 * Author: zhangming
 */
#include <stdio.h>
#include <string.h>
#include <pcap.h>

void packet_handler(u_char *user, const struct pcap_pkthdr *pkt_header, const u_char *pkt_data)
{
	pcap_dump(user, pkt_header, pkt_data);// 输出数据到文件
	printf("a packet with length of [%d]\n", pkt_header->len);// 打印抓到的包的长度
}

int main(int argc, char *argv[])
{
	pcap_t *handle;                 // 会话句柄

	char errbuf[PCAP_ERRBUF_SIZE]; // 存储错误信息的字符串

	bpf_u_int32 mask;               //所在网络的掩码
	bpf_u_int32 net;                //主机的IP地址

	struct bpf_program filter;      //已经编译好的过滤器
	char filter_app[] = "port 80";  //BPF过滤规则,和tcpdump使用的是同一种过滤规则

	/* 探查设备及属性 */
	char *dev;                      //指定需要被抓包的设备 我们在linux下的两个设备eth0和lo分别是网卡和本地环回
	dev = pcap_lookupdev(errbuf);   //返回第一个合法的设备，我这里是eth0
	pcap_lookupnet(dev, &net, &mask, errbuf); //返回接口的子网net和掩码mask
	//dev = "lo";                   //如果需要抓取本地的数据包，比如过滤表达式为host localhost的时候可以直接指定

	/* 以混杂模式打开会话 */
	handle = pcap_open_live(dev, BUFSIZ, 1, 0, errbuf);

	/* 编译并应用过滤器 */
	pcap_compile(handle, &filter, filter_app, 0, net);
	pcap_setfilter(handle, &filter);

	/* 定义输出文件 */
	pcap_dumper_t* out_pcap;
	out_pcap = pcap_dump_open(handle, "/home/zhangming/pack.pcap");

	/* 截获30个包 */
	pcap_loop(handle, 30, packet_handler, (u_char *)out_pcap);

	/* 刷新缓冲区 */
	pcap_dump_flush(out_pcap);

	/* 关闭资源 */
	pcap_close(handle);
	pcap_dump_close(out_pcap);

	return(0);
}