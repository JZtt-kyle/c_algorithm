/* 
 * 题目: 全排列
 * 功能描述: 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 * 网址:https://leetcode.cn/problems/permutations/description/
*/
#include <vector>
using namespace std;

class Solution {
    public:
        int* used = new int[6];
        vector<int> path;
        vector<vector<int>> res;
        vector<vector<int>> permute(vector<int>& nums) {
            backtrack(nums);
            return res;
        }
        void backtrack(vector<int>& nums) {
            if(path.size() == nums.size()) {
                res.push_back(path);
                return;
            }
            for(int i = 0; i < nums.size(); i++) {
                if(used[i] == 1) continue;
                used[i] = 1;
                path.push_back(nums[i]);
                backtrack(nums);
                used[i] = 0;
                path.pop_back();
            }
        }
    };
