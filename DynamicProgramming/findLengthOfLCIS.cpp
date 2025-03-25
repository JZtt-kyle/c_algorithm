/* 
 * 题目: 最长连续递增序列
 * 功能描述: 给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。
连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
 * 网址:https://leetcode.cn/problems/longest-continuous-increasing-subsequence/description/
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int findLengthOfLCIS(vector<int>& nums) {
            int res = 1;
            int j = 0;
            for(int i = 1; i < nums.size(); i++) {
                if(nums[i] > nums[i - 1]) res = max(res, i - j + 1);
                else j = i;
            }
            return res;
        }

        int findLengthOfLCIS(vector<int>& nums) {
            int res = 1;
            vector<int> dp(nums.size(), 1);
            for(int i = 1; i < nums.size(); i++) {
                if(nums[i] > nums[i - 1]) dp[i] = dp[i - 1] + 1;
                res = max(res, dp[i]);
            }
            return res;
        }
    };
