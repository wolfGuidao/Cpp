#include <iostream>
#include <vector>
#include <string.h>
#include <cstdio>
#include <string>
using namespace std;

#if 0

// 使用文件IO流用文本及二进制方式演示读写配置文件
 struct ServerInfo
 {
 char _ip[32]; // ip
 int _port; // 端口
 };
 struct ConfigManager
 {
 public:
 ConfigManager(const char* configfile = "bitserver.config")
 :_configfile(configfile)
 {}
 void WriteBin(const ServerInfo& info)
 {
 // 这里注意使用二进制方式打开写
 ofstream ofs(_configfile, ifstream::in|ifstream::binary);
 ofs.write((const char*)&info, sizeof(ServerInfo));
 ofs.close();
 } 
 void ReadBin(ServerInfo& info)
 {
   // 这里注意使用二进制方式打开读
    ifstream ifs(_configfile, ifstream::out | ifstream::binary);
    ifs.read((char*)&info, sizeof(ServerInfo));
    ifs.close();
 }
 void WriteText(const ServerInfo& info)
 {
   // 这里会发��IO流写整形比C语言那套就简单多了，
    // C 语言得先把整形itoa再写
    ofstream ofs(_configfile);
    ofs << info._ip << endl;
    ofs << info._port << endl;
    ofs.close();
   
 }
 void ReadText(ServerInfo& info)
 {
   // 这里会发现IO流读整形比C语言那套就简单多了，
    // C 语言得先读字符串，再atoi
    ifstream ifs(_configfile);
    ifs >> info._ip;
    ifs >> info._port;
    ifs.close();
 }
 private:
 string _configfile; // 配置文件
 };

#endif

void Func1()
{
  FILE* f1 = fopen("1.txt","wb");

  if(f1 == nullptr)
  {
    perror("open file is error\n");
  }

  //向 文件/标准输出 中写数据
  fputc('i',f1);
  fputs(" am wolf guidao",f1);

  //fseek(f1,0,SEEK_SET);

  const char* temp = "vhajhvnfb;v avn;ldsnvavjafv; aknva;lskdnv\n";

  int a = 2020;
  int b = 01;
  int c = 14;
  fprintf(f1,"  %d年%d月%d日",a,b,c);
  fprintf(f1,"  年月日");

  size_t size1 = fwrite(temp,1,strlen(temp),f1);
  cout<<"size: "<<size1<<endl;
  //fwrite(temp,strlen(temp),1,stdout);

  fclose(f1);
  f1 = nullptr;


  //从 文件/标准输入 中读取数据
  
  FILE* f2 = fopen("1.txt","r");

  //SEEK_SET
  //SEEK_CUR
  //SEEK_END

  cout<<"f2: "<<ftell(f2)<<endl;
  fseek(f2,0,SEEK_END);
  cout<<"f2: "<<ftell(f2)<<endl;
  fseek(f2,0,SEEK_SET);
  cout<<"f2: "<<ftell(f2)<<endl;

  char d = fgetc(f2);
  cout<<endl;
  cout<<" d: "<<d<<endl;

  char s[1024];
  //char* ff = fgets(s,100,f2);
  //cout<<"ff: "<<ff<<" s: "<<s<<endl;

  //char* fff = fgets(s,100,stdin);
  //cout<<fff<<endl;

  //fseek(f2,0,SEEK_SET);
  
  //ftell返回文件指针相对开始位置的偏移量
  cout<<"f2: "<<ftell(f2)<<endl;
  rewind(f2);//把文件指针移到开始
  cout<<"f2: "<<ftell(f2)<<endl;

  char s1[1024];
  size_t size = fread(s1,1,1024,f2);
  cout<<"size: "<<size<<endl;
  cout<<"s1: "<<s1<<endl;

  cout<<"f2: "<<ftell(f2)<<endl;

  fclose(f2);
  f2 = nullptr;

  //追加数据
  FILE* f3 = fopen("1.txt","a");
  fputs(" test \"s\" ",f3);

  FILE* f4 = fopen("2.txt","wb");
  fputs("this is wb",f4);

  //sprintf
  char s2[1024];
  sprintf(s2,"hello world ,this is test sprintf");
  cout<<"s2: "<<s2<<endl;
  sprintf(s2,"12,34,56"); 
  cout<<"s2: "<<s2<<endl;
}

void Func2()
{
  //循环读取，防止空格的影响
  //char c;
  //while((getchar()) != EOF)
  //{
  //  int a;
  //  int b;
  //  cin>>a>>b;
  //  cout<<"a: "<<a<<" b: "<<b<<endl;
  //}
  
}

int main()
{
  //Func1();
  Func2();
  return 0;
}
