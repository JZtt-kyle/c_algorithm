/* 
 * 题目: 分割等和子集
 * 功能描述: 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 网址:https://leetcode.cn/problems/partition-equal-subset-sum/description/
*/

#include <vector>
using namespace std;

class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int sum = 0;
            for(int num : nums) {
                sum += num;
            }
            if (sum % 2 == 1) return false;
            int target = sum / 2;
            vector<int> dp(target + 1, 0);
            for(int i = 0; i < nums.size(); i++) {
                for(int j = target; j >= nums[i]; j--) {
                    dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                }
            }
            return dp[target] == target;
        }
    };