/* 
 * 题目: 买卖股票的最佳时机含手续费
 * 功能描述: 给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。
你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
返回获得利润的最大值。
注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
 * 网址:https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices, int fee) {
            int size = prices.size();
            vector<vector<int>> dp(size, vector<int>(2));
            dp[0][0] = -prices[0], dp[0][1] = 0;
            for(int i = 1; i< size; i++) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
            }
            return dp[size - 1][1];
        }
    };