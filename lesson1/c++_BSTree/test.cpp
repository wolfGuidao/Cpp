#include "bstree.hpp"

void Func1()
{
  BSTree<int> bs1;
  bs1.Insert(4);
  bs1.Insert(3);
  bs1.Insert(2);
  bs1.Insert(7);
  bs1.Insert(5);
  bs1.Print();

  bs1.Erase(2);
  bs1.Print();

  bs1.Insert(9);
  bs1.Insert(0);
  bs1.Insert(6);
  bs1.Print();

  cout<<"this is test:"<<endl;
  bs1.Erase(4);
  bs1.Erase(4);
  bs1.Erase(4);
  bs1.Print();
}

int main()
{
  Func1();
  return 0;
}
