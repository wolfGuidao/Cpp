#include "string.hpp"

void TestBitstring()
{
  wolf::string s1("hello wolf");
  wolf::string s2(s1);
  wolf::string s3 = s2;
  cout<<"test string 构造 : "<<"s1: "<<s1<<" s2: "<<s2<<" s3: "<<s3<<endl;

  wolf::string s4("nihao i am wolf");
  cout<<"test string size: "<<s4<<" size: "<<s4.Size()<<" capacity: "<<s4.Capacity()<<" empty: "<<s4.Empty()<<endl;

  wolf::string s5;
  s5.Reserve(5);
  cout<<"reserve capacity : "<<s5.Capacity()<<endl;
  //s5.Reserve(10);
  //cout<<"reserve capacity : "<<s5.Capacity()<<endl;
  //s5.Reserve(30);
  //cout<<"reserve capacity : "<<s5.Capacity()<<endl;
  //s5.Reserve(100);
  //cout<<"reserve capacity : "<<s5.Capacity()<<endl;

  //s5.Resize(10,'a');
  //cout<<"reserve capacity : "<<s5.Capacity()<<" resize size : "<<s5.Size()<<endl;

  //s5.Push_back('b');
  //cout<<"pushback capacity : "<<s5.Capacity()<<" resize size : "<<s5.Size()<<endl;
  
  wolf::string s6("wolf");
  cout<<"+= capacity: "<<s6.Capacity()<<" size: "<<s6.Size()<<endl;
  s6 += 'g';
  cout<<"+= capacity: "<<s6.Capacity()<<" size: "<<s6.Size()<<endl;
  s6 += "guidao";
  cout<<"+= capacity: "<<s6.Capacity()<<" size: "<<s6.Size()<<endl;
  s6 += "aaa";
  wolf::string s7("hhhh");
  s6 += s7;
  cout<<"+= capacity: "<<"s6 : "<<s6<<" "<<s6.Capacity()<<" size: "<<s6.Size()<<endl;

  cout<<"+= capacity: "<<s7.Capacity()<<" size: "<<s7.Size()<<endl;
  s7.Append("wolf");
  cout<<"+= capacity: "<<s7.Capacity()<<" size: "<<s7.Size()<<endl;
  s7.Append("wolf");
  cout<<"+= capacity: "<<s7<<" "<<s7.Capacity()<<" size: "<<s7.Size()<<endl;
  //s7.Clear();
  cout<<"+= capacity: "<<s7.Capacity()<<" size: "<<s7.Size()<<endl;

  cout<<"test : "<<endl;
  cout<<"s6: "<<s6<<" s7: "<<s7<<endl;
  cout<<"+= capacity: "<<s7<<" "<<s7.Capacity()<<" size: "<<s7.Size()<<endl;
  cout<<"+= capacity: "<<s6.Capacity()<<" size: "<<s6.Size()<<endl;
  s6.Swap(s7);
  cout<<"s6: "<<s6<<" s7: "<<s7<<endl;
  cout<<"+= capacity: "<<s7<<" "<<s7.Capacity()<<" size: "<<s7.Size()<<endl;
  cout<<"+= capacity: "<<s6.Capacity()<<" size: "<<s6.Size()<<endl;

  //cout<<s7[0]<<" : "<<s7[s7.Size() - 1]<<" : "<<s7[-1]<<endl;
  cout<<s7[0]<<" : "<<s7[s7.Size() - 1]<<endl;

  wolf::string s8("wolf");
  wolf::string s81("wolf");
  wolf::string s9("wolfa");
  wolf::string s10("wol");
  cout<<"s8:"<<s8<<" s9: "<<s9<<" s10: "<<s10<<endl;
  cout<<"test > : "<<s8.operator<(s10)<<endl;
  //cout<<"test > : "<<s8.operator<(s9)<<endl;
  cout<<"test > : "<<s8.operator!=(s81)<<endl;

  wolf::string s11("aaaaa hello world guidao");
  cout<<s11.Find("hello")<<" "<<s11.Find("hello",1)<<endl;
  cout<<s11.rFind("hello",15)<<" "<<s11.rFind("hello",8)<<endl;

  wolf::string s12("hew");
  cout<<s12<<endl;
  //cout<<*s12.Erase(1)<<endl;
  auto it = s12.begin();
  it = s12.Erase(1);
  cout<<*it<<endl;
  cout<<s12<<endl;

  cout<<s12<<" size: "<<s12.Size()<<" capacity: "<<s12.Capacity()<<endl;
  s12.Insert(0,'h');
  cout<<s12<<" size: "<<s12.Size()<<" capacity: "<<s12.Capacity()<<endl;
  s12.Insert(2,'o');
  cout<<s12<<" size: "<<s12.Size()<<" capacity: "<<s12.Capacity()<<endl;
}

int main()
{
  TestBitstring();
  return 0;
}
