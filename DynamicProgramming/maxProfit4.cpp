/* 
 * 题目: 买卖股票的最佳时机Ⅳ
 * 功能描述: 给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 网址:https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int maxProfit(int k, vector<int>& prices) {
            int size = prices.size();
            vector<vector<int>> dp(size, vector<int>(2 * k + 1));
            for(int i = 0; i <= 2 * k; i++) {
                if(i % 2 == 0) dp[0][i] = 0;
                else dp[0][i] = - prices[0];
            }
            for(int i = 1; i < size; i++) {
                for(int j = 1; j <= 2 * k; j++) {
                    if(j % 2 == 0) {
                        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
                    }else {
                        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                    }
                }
            }
            return dp[size - 1][2 * k];
        }
    };