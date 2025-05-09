/* 
 * 题目: 最佳买卖股票时机含冷冻期
 * 功能描述: 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 网址:https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int size = prices.size();
            vector<vector<int>> dp(size, vector<int>(3));
            dp[0][0] = -prices[0], dp[0][1] = 0, dp[0][2] = 0;
            for(int i = 1; i < size; i++) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
            }
            return dp[size - 1][1];
        }
    };