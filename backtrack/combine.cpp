/* 
 * 题目: 组合
 * 功能描述: 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
你可以按 任何顺序 返回答案。
 * 网址:https://leetcode.cn/problems/combinations/description/
*/
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> res;
        vector<int> path;
        vector<vector<int>> combine(int n, int k) {
            backtrack(n, k, 1);
            return res;
        }
        void backtrack(int n, int k, int startIndex) {
            if(path.size() == k) {
                res.push_back(path);
                return;
            }
            for(int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
                path.push_back(i);
                backtrack(n, k, i + 1);
                path.pop_back();
            }
        }
    };