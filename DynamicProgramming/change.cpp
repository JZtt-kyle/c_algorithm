/* 
 * 题目: 零钱兑换II
 * 功能描述: 给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
假设每一种面额的硬币有无限个。 
题目数据保证结果符合 32 位带符号整数。
 * 网址:https://leetcode.cn/problems/coin-change-ii/description/
*/


#include <vector>
using namespace std;

class Solution {
    public:
        int change(int amount, vector<int>& coins) {
            vector<unsigned long long> dp(amount + 1);
            dp[0] = 1;
            for(int i = 0; i < coins.size(); i++) {
                for(int j = coins[i]; j <= amount; j++) {
                    dp[j] += dp[j - coins[i]];
                }
            }
            return dp[amount];
        }
    };