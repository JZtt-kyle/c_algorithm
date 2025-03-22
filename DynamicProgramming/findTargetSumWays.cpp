/* 
 * 题目: 目标和
 * 功能描述: 给你一个非负整数数组 nums 和一个整数 target 。
向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 * 网址:https://leetcode.cn/problems/target-sum/description/
*/


#include <vector>
using namespace std;

class Solution {
    public:
        int res;
        int findTargetSumWays(vector<int>& nums, int target) {
            backtrack(nums, target, 0);
            return res;
        }
        void backtrack(vector<int>& nums, int target, int depth) {
            if(depth == nums.size()) {
                if(target == 0) res++;
                return;
            }
            backtrack(nums, target - nums[depth], depth + 1);
            backtrack(nums, target + nums[depth], depth + 1);
        }
        int findTargetSumWays(vector<int>& nums, int target) {
            int sum = 0;
            for(int num : nums) {
                sum += num;
            }
            if((sum + target) % 2 == 1) return 0;
            if(abs(target) > sum) return 0;
            int x = (sum + target) / 2;
            vector<int> dp(x + 1, 0);
            dp[0] = 1;
            for(int i = 0; i < nums.size(); i++) {
                for(int j = x; j >= nums[i]; j--) {
                    dp[j] += dp[j - nums[i]];
                }
            }
            return dp[x];
        }
    };