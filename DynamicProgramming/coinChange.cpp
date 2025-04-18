/* 
 * 题目: 零钱兑换
 * 功能描述: 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
你可以认为每种硬币的数量是无限的。
 * 网址:https://leetcode.cn/problems/coin-change/description/
*/


#include <vector>
using namespace std;

class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            vector<int> dp(amount + 1, 0x7ffffffe);
            dp[0] = 0;
            for(int i = 0; i < coins.size(); i++) {
                for(int j = coins[i]; j <= amount; j++) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
            return dp[amount] == 0x7ffffffe ? -1 : dp[amount];
        }
    };