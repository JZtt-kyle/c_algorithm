/* 
 * 题目: 判断子序列
 * 功能描述: 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
 * 网址:https://leetcode.cn/problems/is-subsequence/description/
*/

#include <vector>
# include <string>
using namespace std;

class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int i = 0, j = 0;
            int lenS = s.size(), lenT = t.size();
            while(i < lenS && j < lenT) {
                if(s[i] == t[j]) {
                    i++;
                }
                j++;
            }
            return i == lenS;
        }

        bool isSubsequence(string s, string t) {
            int lenS = s.size(), lenT = t.size();
            vector<vector<int>> dp(lenS + 1, vector<int>(lenT + 1, 0));
            for(int i = 1; i <= lenS; i++) {
                for(int j = 1; j <= lenT; j++) {
                    if(s[i - 1] == t[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }else {
                        dp[i][j] = dp[i][j - 1];
                    }
                }
            }
            return dp[lenS][lenT] == lenS;
        }
    };