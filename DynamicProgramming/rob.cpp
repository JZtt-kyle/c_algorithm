/* 
 * 题目: 打家劫舍
 * 功能描述: 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
 * 网址:https://leetcode.cn/problems/house-robber/description/
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int res = 0;
        int rob(vector<int>& nums) {
            vector<bool> used(nums.size(), false);
            backtrack(nums, used, 0, 0);
            return res;
        }

        int rob(vector<int>& nums) {
            vector<int> dp(nums.size() + 1, 0);
            dp[0] = 0, dp[1] = nums[0];
            for(int i = 2; i <= nums.size(); i++) {
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
            }
            return dp[nums.size()];
        }

        void backtrack(vector<int>& nums, vector<bool>& used, int startIndex, int sum) {
            if(sum > res) {
                    res = sum;
                }
            if(startIndex == nums.size()) return;
            for(int i = startIndex; i < nums.size(); i++) {
                if(i > 0 && used[i - 1]) continue;
                used[i] = true;
                backtrack(nums, used, i + 1, sum + nums[i]);
                used[i] = false;
            }
        }
    };

