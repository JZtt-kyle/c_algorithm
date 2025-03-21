/* 
 * 题目: 斐波那契数列
 * 功能描述: 斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。
 * 网址:https://leetcode.cn/problems/fibonacci-number/description/
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int fib(int n) {
            if(n == 0) return 0;
            if(n == 1) return 1;
            vector<int> dp(n + 1, 0);
            dp[1] = 1;
            for(int i = 2; i <= n; i++) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[n];
        }
    };