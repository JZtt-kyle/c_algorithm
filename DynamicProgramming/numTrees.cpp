/* 
 * 题目: 不同的二叉搜索树
 * 功能描述: 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
 * 网址:https://leetcode.cn/problems/unique-binary-search-trees/description/
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int numTrees(int n) {
            vector<int> dp(n + 1);
            dp[0] = 1;
            for(int i = 1; i <=n; i++) {
                for(int j = 0; j <= i - 1; j++) {
                    dp[i] += dp[j] * dp[i - j - 1];
                }
            }
            return dp[n];
        }
    };