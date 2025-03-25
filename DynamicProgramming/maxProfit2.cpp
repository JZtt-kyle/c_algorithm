/* 
 * 题目: 买卖股票的最佳时机Ⅱ
 * 功能描述: 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
返回 你能获得的 最大 利润 。
 * 网址:https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int size = prices.size();
            vector<vector<int>> dp(size, vector<int>(2));
            dp[0][0] = -prices[0], dp[0][1] = 0;
            for(int i = 1; i < size; i++) {
                dp[i][0] = max(dp[i - 1][1] - prices[i], dp[i - 1][0]);
                dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
            }
            return dp[size - 1][1];
        }
    };