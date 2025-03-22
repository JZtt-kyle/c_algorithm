/* 
 * 题目: 一和零
 * 功能描述: 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
 * 网址:https://leetcode.cn/problems/ones-and-zeroes/description/
*/


#include <vector>
using namespace std;

class Solution {
    public:
        int findMaxForm(vector<string>& strs, int m, int n) {
            vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
            vector<int> count = getCount(strs[0]);
            for(int i = 0; i <= m; i++) {
                for(int j = 0; j <= n; j++) {
                    if(i >= count[0] && j >= count[1]) dp[i][j] = 1;
                }
            }
            for(int l = 1; l < strs.size(); l++) {
                count = getCount(strs[l]);
                for(int i = m; i >= count[0]; i--) {
                    for(int j = n; j >= count[1]; j--) {
                        dp[i][j] = max(dp[i][j], dp[i - count[0]][j - count[1]] + 1) ;
                    }
                }
            }
            return dp[m][n];
        }
        vector<int> getCount(string s) {
            int count_0 = 0, count_1 = 0;
            for(char c : s) {
                if(c == '0') count_0++;
                else count_1++;
            }
            return {count_0, count_1};
        }
    };