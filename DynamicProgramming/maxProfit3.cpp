/* 
 * 题目: 买卖股票的最佳时机Ⅲ
 * 功能描述: 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 网址:https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int size = prices.size();
            vector<vector<int>> dp(size, vector<int>(5));
            dp[0][0] = 0, dp[0][1] = -prices[0], dp[0][2] = 0, dp[0][3] = -prices[0], dp[0][4] = 0;
            for(int i = 1; i < size; i++) {
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
                dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
                dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
            }
            return dp[size - 1][4];
        }
    };