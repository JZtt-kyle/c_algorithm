/* 
 * 题目: 爬楼梯
 * 功能描述: 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 网址:https://leetcode.cn/problems/climbing-stairs/description/
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int climbStairs(int n) {
            if(n <= 1) return n;
            vector<int> dp(n + 1);
            dp[1] = 1;
            dp[2] = 2;
            for(int i = 3; i <= n; i++) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[n];
        }
    };