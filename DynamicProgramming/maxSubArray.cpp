/* 
 * 题目: 最大子序和
 * 功能描述: 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组是数组中的一个连续部分。
 * 网址:https://leetcode.cn/problems/maximum-subarray/description/
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int res = nums[0];
            vector<int> dp(nums.size());
            dp[0] = nums[0];
            for(int i = 1; i < nums.size(); i++) {
                dp[i] = max(dp[i - 1] + nums[i], nums[i]);
                if(res < dp[i]) res = dp[i];
            }
            return res;
        }
    };