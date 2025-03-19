/* 
 * 题目: 组合总和Ⅲ
 * 功能描述: 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
只使用数字1到9
每个数字 最多使用一次 
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
 * 网址:https://leetcode.cn/problems/combination-sum-iii/description/
*/
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> res;
        vector<int> path;
        vector<vector<int>> combinationSum3(int k, int n) {
            backtrack(k, n, 1);
            return res;
        }
        void backtrack(int k, int n, int startIndex) {
            if(n < 0) return;
            if(path.size() == k) {
                if(n == 0) res.push_back(path);
                return;
            }
            for(int i = startIndex; i <= 10 - (k - path.size()); i++){
                path.push_back(i);
                backtrack(k, n - i, i + 1);
                path.pop_back();
            }
        }
    };