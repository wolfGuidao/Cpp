#include <iostream>
#include <string.h>
#include <winsock2.h>
#include <ws2ipdef.h>
#include <mstcpip.h>
#include <process.h>
#include "packdef.h"

#pragma comment (lib,"ws2_32.lib")

using namespace std;

int main()
{
	//1.加载库
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {

		printf("WSAStartup failed with error: %d\n", err);
		return 1;
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {

		printf("Could not find a usable version of Winsock.dll\n");
		WSACleanup();
		return 1;
	}
	else
		printf("The Winsock 2.2 dll was found okay\n");

	//建立原始套接字
	SOCKET sniffersock;
	sniffersock = socket(AF_INET, SOCK_RAW/*原始套接字*/, IPPROTO_IP);
	if (INVALID_SOCKET == sniffersock)
	{
		closesocket(sniffersock);
		WSACleanup();
	}

	//获取本机名称
	char hostname[DEFAULT_NAMELEN];
	if (SOCKET_ERROR == gethostname(hostname, DEFAULT_NAMELEN))
	{
		cout << "获取本机名失败" << endl;
		WSACleanup();
		return 1;
	}

	//获取本机可用IP地址
	HOSTENT* local;
	local = gethostbyname(hostname);
	if (NULL == local)
	{
		cout << "获取本机IP地址失败" << endl;
		WSACleanup();
		return 1;
	}
	//输出可用IP
	cout << "本机可用IP地址有" << endl;
	int i = 0;
	int num;
	IN_ADDR myAddr;
	while (local->h_addr_list[i] != 0)
	{
		myAddr.s_addr = *(u_long*)local->h_addr_list[i++];
		cout << i << ":  " << inet_ntoa(myAddr) << endl;
	}
	//监听sock与所选IP绑定
	cout << "选择使用的接口号" << endl;
	cin >> num;
	SOCKADDR_IN localAddr;
	localAddr.sin_family = AF_INET;
	localAddr.sin_port = 0;
	memset(&localAddr.sin_addr.S_un.S_addr, 0, sizeof(localAddr.sin_addr.S_un.S_addr));
	memcpy(&localAddr.sin_addr.S_un.S_addr, local->h_addr_list[num - 1],
		sizeof(localAddr.sin_addr.S_un.S_addr));

	if (SOCKET_ERROR == bind(sniffersock, (const sockaddr*)&localAddr, sizeof(localAddr)))
	{
		closesocket(sniffersock);
		WSACleanup();
		return 1;
	}

	//将网卡置于混杂模式，接收所有数据
	u_long sioarg = 1;
	DWORD dwValue = 0;
	if (SOCKET_ERROR == WSAIoctl(sniffersock, SIO_RCVALL, &sioarg, sizeof(sioarg), NULL, 0, &dwValue, NULL, NULL))
	{
		closesocket(sniffersock);
		return 1;
	}

	//开始接受数据  
	cout << "开始接受数据" << endl << endl;
	//接收数据 获取数据包信息
	sockaddr_in clientAddr;
	int nsize = sizeof(clientAddr);
	int len = 0;
	char buf[DEF_PACKDEFSIZE] = { 0 };
	while (1)
	{
		len = recv(sniffersock, buf, DEF_PACKDEFSIZE, 0);
		if (len > 0)
		{
			IPHEAD iphead = *(IPHEAD*)buf;
			cout << "版本号:" << (iphead.version_hl >> 4) << endl;
			cout << "首部长度:" << (iphead.version_hl & 15) << endl;
			cout << "长度:" << iphead.tot_len << endl;
			cout << "协议:" << (int)iphead.protocol << endl;
			cout << "源地址:" << inet_ntoa(*(in_addr *)&iphead.saddr) << endl;
			cout << "目的地址:" << inet_ntoa(*(in_addr *)&iphead.daddr) << endl;
			cout << endl;
		}
		else
			cout << "接收失败" << endl;
	}

	return 0;
}