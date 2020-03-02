#include "Kmp.hpp"

int TestKmp()
{
  KMP kk("abcd.");
  return kk.Search("aabbcdaabbcabcd.AAbbcc");
}

int main()
{
  std::cout<<TestKmp()<<std::endl;
  return 0;
}
