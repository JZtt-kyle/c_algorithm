/* 
 * 题目: 不同子序列
 * 功能描述: 给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数，结果需要对 109 + 7 取模。
 * 网址:https://leetcode.cn/problems/distinct-subsequences/description/
*/

#include <vector>
# include <string>
using namespace std;

class Solution {
    public:
        int numDistinct(string s, string t) {
            int lenS = s.size(), lenT = t.size();
            vector<vector<int>> dp(lenS + 1, vector<int>(lenT + 1, 0));
            for(int i = 0; i <= lenS; i++) dp[i][0] = 1;
            for(int i = 1; i <= lenS; i++) {
                for(int j = 1; j <= lenT; j++) {
                    if(s[i - 1] == t[j - 1]) {
                        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % (int)(1e9 + 7);
                    }
                    else {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
            return dp[lenS][lenT];
        }
    };

