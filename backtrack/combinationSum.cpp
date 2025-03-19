/* 
 * 题目: 组合总和
 * 功能描述: 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
对于给定的输入，保证和为 target 的不同组合数少于 150 个。
 * 网址:https://leetcode.cn/problems/combination-sum/description/
*/
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> path;
        vector<vector<int>> res;
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
                int num = candidates[i];
                path.push_back(num);
                backtrack(candidates, target - num, i);
                path.pop_back();
            }
        }
    };