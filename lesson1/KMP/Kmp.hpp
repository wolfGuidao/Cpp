#include "Header.hpp"

//封装一个KMP算法用来快速查找字符串匹配
class KMP
{
  public:
    KMP(const std::string& pat)
      :_pat(pat)
    {
      int M = _pat.size();

      //dp[状态][字符] = 下一个状态；把dp初始化为全0
      dp = std::vector<std::vector<int>>(M,std::vector<int>(256,0));

      //base case ：一开始dp中存的是0，那么规定最开始为0状态，遇到第一个字符为pat转换为1状态
      dp[0][_pat[0]] = 1;

      //博客中说的影子状态，初始化为0状态
      int X = 0;

      //开始循环构造状态转换图即dp
      for(int j = 1;j < M;j++)
      {
        for(int c = 0;c < 256;c++)
        {
          dp[j][c] = dp[X][c];
        }
        dp[j][_pat[j]] = j + 1;

        //更新影子状态
        X = dp[X][_pat[j]];
      }
    }

    int Search(const std::string& txt)
    {
      int M = _pat.size();
      int N = txt.size();

      //pat的初始状态为0状态
      int j = 0;

      //循环
      for(int i = 0;i < N;i++)
      {
        j = dp[j][txt[i]];

        //如果经过状态转换图dp可以到达终态M，就说明在txt中成功找到匹配的字符串，直接返回其在txt中的下标索引
        if(j == M)
        {
          return i - M + 1;
        }
      }

      //代码走到这里代表遍历完txt还没有找到匹配的return出去，就直接return -1；
      return -1;
    }


  private:

    //dp存放状态转换图;dp[1]['A'] = 2;代表 状态1 如果遇到字符'A'，pat 就转换为2状态
    std::vector<std::vector<int>> dp;

    //用户输入pat待匹配的字符串
    std::string _pat;
};
