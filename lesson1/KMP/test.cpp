#include "Kmp.hpp"

int TestKmp()
{
  KMP kk("aabbcc");
  return kk.Search("aabbcdaabbcabbcaabbcc");
}

int main()
{
  std::cout<<TestKmp()<<std::endl;
  return 0;
}
