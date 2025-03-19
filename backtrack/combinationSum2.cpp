/* 
 * 题目: 组合总和Ⅱ
 * 功能描述: 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用 一次 。
注意：解集不能包含重复的组合。 
 * 网址:https://leetcode.cn/problems/combination-sum-ii/description/
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<int> path;
        vector<vector<int>> res;
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            backtrack(candidates, target, 0);
            return res;
        }
        void backtrack(vector<int>& candidates,  int target, int startIndex) {
            if(target < 0) return;
            if(target == 0) {
                res.push_back(path);
                return;
            }
            for(int i = startIndex; i < candidates.size(); i++) {
                if(i > startIndex && candidates[i] == candidates[i - 1]) continue;
                int num = candidates[i];
                path.push_back(num);
                backtrack(candidates, target - num, i + 1);
                path.pop_back();
            }
        }
    };