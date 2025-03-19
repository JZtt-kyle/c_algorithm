/* 
 * 题目: 递增子序列
 * 功能描述: 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
 * 网址:https://leetcode.cn/problems/non-decreasing-subsequences/description/
*/
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> path;
        vector<vector<int>> res;
        vector<vector<int>> findSubsequences(vector<int>& nums) {
            backtrack(nums, 0);
            return res;
        }
        void backtrack(vector<int>& nums, int startIndex) {
            if(path.size() >= 2) {
                res.push_back(path);
            }
            int used[201] = {0};
            for(int i = startIndex; i < nums.size(); i++) {
                if(!path.empty() && nums[i] < path[path.size() - 1]) continue;
                if(used[nums[i] + 100] == 1) continue;
                used[nums[i] + 100] = 1;
                path.push_back(nums[i]);
                backtrack(nums, i + 1);
                path.pop_back();
            }
        }
    };