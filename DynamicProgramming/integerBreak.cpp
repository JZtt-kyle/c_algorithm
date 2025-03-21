/* 
 * 题目: 整数拆分
 * 功能描述: 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
 * 网址:https://leetcode.cn/problems/integer-break/
*/

#include <vector>
using namespace std;


class Solution {
    public:
        int integerBreak(int n) {
            vector<int> dp(n + 1);
            dp[0] = 0, dp[1] = 1;
            for(int i = 2; i <= n; i++) {
                for(int j = 1; j < i; j++) {
                    dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
                }
            }
            return dp[n];
        }
    };