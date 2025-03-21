/* 
 * 题目: 使用最小花费爬楼梯
 * 功能描述: 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
请你计算并返回达到楼梯顶部的最低花费。
 * 网址:https://leetcode.cn/problems/min-cost-climbing-stairs/description/
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int size = cost.size();
            if(size == 1) return cost[0];
            if(size == 2) return cost[0] < cost[1] ? cost[0] : cost[1];
            vector<int> dp(cost.size() + 1);
            dp[0] = 0, dp[1] = 0;
            for(int i = 2; i <= size; i++) {
                dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
            }
            return dp[size];
        }
    };