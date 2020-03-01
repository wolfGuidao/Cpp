#include "Header.hpp"

class KMP
{
  public:
    KMP(const std::string& pat)
      :_pat(pat)
    {
      int M = _pat.size();

      //dp[状态][字符] = 下一个状态
      dp = std::vector<std::vector<int>>(M,std::vector<int>(256,0));

      //base case 
      dp[0][_pat[0]] = 1;

      int X = 0;

      for(int j = 1;j < M;j++)
      {
        for(int c = 0;c < 256;c++)
        {
          dp[j][c] = dp[X][c];
        }
        dp[j][_pat[j]] = j + 1;

        X = dp[X][_pat[j]];
      }
    }

    int Search(const std::string& txt)
    {
      int M = _pat.size();
      int N = txt.size();

      int j = 0;
      for(int i = 0;i < N;i++)
      {
        j = dp[j][txt[i]];
        if(j == M)
        {
          return i - M + 1;
        }
      }
      return -1;
    }


  private:

    //dp存放状态转换图;dp[1]['A'] = 2;代表 状态1 如果遇到字符'A'，pat 就转换为2状态
    std::vector<std::vector<int>> dp;

    //用户输入pat
    std::string _pat;
};
