/* 
 * 题目: 最长重复子数组
 * 功能描述: 给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。
 * 网址:https://leetcode.cn/problems/maximum-length-of-repeated-subarray/description/
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int findLength(vector<int>& nums1, vector<int>& nums2) {
            int res = 0;
            int len1 = nums1.size(), len2 = nums2.size();
            vector<vector<int>> dp(len1, vector<int>(len2, 0));
            for(int i = 0; i < len1; i ++) {
                if(nums1[i] == nums2[0]) {
                    dp[i][0] = 1;
                    res = 1;
                } 
            }
            for(int j = 0; j < len2; j ++) {
                if(nums2[j] == nums1[0]) {
                    dp[0][j] = 1;
                    res = 1;
                } 
            }
            for(int i = 1; i < len1; i++) {
                for(int j = 1; j < len2; j ++) {
                    if(nums1[i] == nums2[j]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                        res = max(res, dp[i][j]);
                    } 
                }
            }
            return res;
        }
    };