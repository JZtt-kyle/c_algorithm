/* 
 * 题目: 买卖股票的最佳时机
 * 功能描述: 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
 * 网址:https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if(prices.size() < 2) return 0;
            int min_price = prices[0];
            int max_profit = 0xffffffff;
            for(int i = 1; i < prices.size(); i++) {
                if(prices[i] < min_price) min_price = prices[i];
                if(max_profit < prices[i] - min_price) max_profit = prices[i] - min_price;
            }
            return max_profit;
        }

        int maxProfit(vector<int>& prices) {
            int size = prices.size();
            vector<vector<int>> dp(size, vector<int>(2));
            dp[0][0] = -prices[0], dp[0][1] = 0;
            for(int i = 1; i < size; i++) {
                dp[i][0] = max(dp[i - 1][0], -prices[i]);
                dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
            }
            return dp[size - 1][1];
        }
    };