/* 
 * 题目: 子集
 * 功能描述: 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 * 网址:https://leetcode.cn/problems/subsets/description/
*/
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> path;
        vector<vector<int>> res;
        vector<vector<int>> subsets(vector<int>& nums) {
            backtrack(nums, 0);
            return res;
        }
        void backtrack(vector<int>& nums, int startIndex) {
            res.push_back(path);
            if(startIndex >= nums.size()) return;
            for(int i = startIndex; i < nums.size(); i++) {
                path.push_back(nums[i]);
                backtrack(nums, i + 1);
                path.pop_back();
            }
        }
    };