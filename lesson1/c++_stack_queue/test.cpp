#include <iostream>
#include <functional>
#include <stack>
#include <queue>
using namespace std;

class MinStack
{
  //最小栈

  public:
    void push(int x)
    {
      _elem.push(x);

      if(_min.empty() || x <= _min.top())//两个判断条件不能换位置
      {
        _min.push(x);
      }
    }

    void pop()
    {
      if(_min.top() == _elem.top())
      {
        _min.pop();
      }

      _elem.pop();
    }

    int top()
    {
      return _elem.top();
    }

    int GetMin()
    {
      return _min.top();
    }
  
  private:
    stack<int> _elem;
    stack<int> _min;
};  

class Solution
{
  //栈的弹出压入序列判断
  public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV)
    {
      if(pushV.size() != popV.size())//两个序列长度不一样肯定不是
      {
        return false;
      }

      stack<int>s;
      size_t index = 0;//记录pushV中的下标
      size_t outdex = 0;//记录popV中的下标

      while(outdex < popV.size())//循环条件，如果outdex在范围内就进行判断，该程序是，一旦跳出循环就直接
        //return true
      {
        while(s.empty() || s.top() != popV[outdex])//当栈为空时，或者栈顶元素和输出序列的元素不相等时
          //进入循环
        {
          if(index < pushV.size())//如果pushV下标在范围内，就进行判断，反之，一旦出范围之外就代表出错，直接
            //返回
          {
            s.push(pushV[index]);
            index++;
          }
          else
          {
            return false;
          }
        }
        //程序走到这里就说明栈顶元素和popV元素相等，说明当前数字就是正确的出栈顺序，后移outdex
        outdex++;
        s.pop();
      }
      return true;
    }
};


class Date
{
  public:
    Date(int year = 1900, int month = 1, int day = 1)
      : _year(year)
        , _month(month)
        , _day(day)
  {}
    bool operator<(const Date& d)const
    {
      cout<<"this is operator<(const Date& d)"<<endl;
      return (_year < d._year) ||
        (_year == d._year && _month < d._month) ||
        (_year == d._year && _month == d._month && _day < d._day);

    }
    bool operator>(const Date& d)const
    {
      cout<<"this is operator>(const Date& d)"<<endl;
      return (_year > d._year) ||
        (_year == d._year && _month > d._month) ||
        (_year == d._year && _month == d._month && _day > d._day);

    }
    //bool operator<(const Date* d)const
    //{
    //  cout<<"this is operator<(const Date* d)"<<endl;
    //  return (_year < d->_year) ||
    //    (_year == d->_year && _month < d->_month) ||
    //    (_year == d->_year && _month == d->_month && _day < d->_day);

    //}
    //bool operator>(const Date* d)const
    //{
    //  cout<<"this is operator>(const Date* d)"<<endl;
    //  return (_year > d->_year) ||
    //    (_year == d->_year && _month > d->_month) ||
    //    (_year == d->_year && _month == d->_month && _day > d->_day);

    //}
    

    friend ostream& operator<<(ostream& _cout, const Date& d)
    {
      _cout << d._year << "-" << d._month << "-" << d._day;
      return _cout;
    }
    bool operator()(const Date* pLeft, const Date* pRight)
    {
      cout<<"this is operator()(const Date* pLeft, const Date* pRight)"<<endl;
      return *pLeft < *pRight;
    }

    Date& operator*()
    {
      cout<<"this is operator*()"<<endl;
      return *this;
    }

    Date* operator&()
    {
      return this;
    }

  private:
    int _year;
    int _month;
    int _day;
};

class Less
{
  public:
    bool operator()(const Date* pLeft, const Date* pRight)
    {
      cout<<"this is Less"<<endl;
      return *pLeft < *pRight;
    }
};
class Greater
{
  public:
    bool operator()(const Date* pLeft, const Date* pRight)
    {
      cout<<"this is Greater"<<endl;
      return *pLeft > *pRight;
    }
};

class Less1
{
  public:
    bool operator()(const Date& l,const Date& r)
    {
      cout<<"this is Less1"<<endl;
      return l < r;
    }
};

void TestPriorityQueue()
{
  // 自己定制比较的规则
   priority_queue<Date*, vector<Date*>,greater<Date*>> q;
   q.push(&Date(2018, 10, 29));
   q.push(&Date(2018, 10, 38));
   q.push(&Date(2018, 10, 30));
   q.push(&Date(2018, 10, 33));
   cout << *q.top() << endl;
   priority_queue<Date*,vector<Date*>,Greater> q1;
   q1.push(&Date(2018, 10, 29));
   q1.push(&Date(2018, 10, 28));
   q1.push(&Date(2018, 10, 30));
   cout << *q1.top() << endl;
  
}

//void TestPriorityQueue()
//{
//  // 大堆，需要用户在自定义类型中提供<的重载
//   //priority_queue<Date> q1;
//   //q1.push(Date(2018, 10, 29));
//   //q1.push(Date(2018, 10, 28));
//   //q1.push(Date(2018, 10, 30));
//   //cout << q1.top() << endl;
//   // 如果要创建小堆，需要用户提供>的重载
//   priority_queue<Date, vector<Date>, Less1> q2;
//   q2.push(Date(2018, 10, 39));
//   q2.push(Date(2018, 10, 28));
//   q2.push(Date(2018, 10, 28));
//   q2.push(Date(2018, 10, 38));
//   q2.push(Date(2018, 10, 30));
//   cout << q2.top() << endl;
//  
//}

void Func1()
{
  MinStack s1;
  s1.push(2);
  s1.push(1);
  s1.push(4);
  s1.push(6);
  s1.push(0);

  cout<<" top: "<<s1.top()<<" min: "<<s1.GetMin()<<endl;

  Solution s2;
  vector<int> pushV = {7,3,2,4,1,9};
  vector<int> popV = {9,1,4,2,3,7};
  cout<<s2.IsPopOrder(pushV,popV)<<endl;

  vector<int> v1 = {2,5,2,8,6,1,0,9,7};
  priority_queue<int,vector<int>,greater<int>>pq(v1.begin(),v1.end());
  priority_queue<int,vector<int>>pq1(v1.begin(),v1.end());
  cout<<pq.top()<<endl;
  cout<<pq1.top()<<endl;
}

void Func2()
{
  vector<int> v1 = {6,3,8,2,9,9,0,6,5,1};

  for(auto e : v1)
  {
    cout<<e<<" ";
  }
  cout<<endl;

  greater<int> comp;//默认情况下是less，可以使用greater
  make_heap(v1.begin(),v1.end(),comp);//把v1构建成一个堆

  for(auto e : v1)
  {
    cout<<e<<" ";
  }
  cout<<endl;

  v1.push_back(66);
  push_heap(v1.begin(),v1.end(),comp);
  //make_heap(v1.begin(),v1.end());

  for(auto e : v1)
  {
    cout<<e<<" ";
  }
  cout<<endl;
}

int main()
{
  //Func1();
  //Func2();
  TestPriorityQueue();
  return 0;
}
