/* 
 * 题目: 全排列Ⅱ
 * 功能描述: 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 * 网址:https://leetcode.cn/problems/permutations-ii/description/
*/
#include <vector>
using namespace std;

class Solution {
    public:
        int* used1 = new int[8];
        vector<int> path;
        vector<vector<int>> res;
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            backtrack(nums);
            return res;
        }
        void backtrack(vector<int>& nums) {
            if(path.size() == nums.size()) {
                res.push_back(path);
                return;
            }
            int* used2 = new int[21];
            for(int i = 0; i < nums.size(); i++) {
                if(used1[i] == 1 || used2[nums[i] + 10] == 1) continue;
                used1[i] = 1;
                used2[nums[i] + 10] = 1;
                path.push_back(nums[i]);
                backtrack(nums);
                path.pop_back();
                used1[i] = 0;
            }
        }
    };