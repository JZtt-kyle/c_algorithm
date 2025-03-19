/* 
 * 题目: 子集Ⅱ
 * 功能描述: 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的 子集（幂集）。
解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
 * 网址:https://leetcode.cn/problems/subsets-ii/description/
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<int> path;
        vector<vector<int>> res;
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            backtrack(nums, 0);
            return res;
        }
        void backtrack(vector<int>& nums, int startIndex) {
            res.push_back(path);
            for(int i = startIndex; i < nums.size(); i++) {
                if(i > startIndex && nums[i] == nums[i - 1]) continue;
                path.push_back(nums[i]);
                backtrack(nums, i + 1);
                path.pop_back();
            }
        }
    };