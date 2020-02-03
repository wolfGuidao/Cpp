#include <iostream>
#include <deque>
using namespace std;

void Func1()
{
  deque<int> dq1 = {1,2,3,4,5};
  cout<<dq1[0]<<endl;
  dq1.push_front(0);
  cout<<dq1[0]<<endl;
}

int main()
{
  Func1();
  return 0;
}
