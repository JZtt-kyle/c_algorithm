/* 
 * 题目: 打家劫舍Ⅱ
 * 功能描述: 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
 * 网址:https://leetcode.cn/problems/house-robber-ii/description/
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int rob(vector<int>& nums) {
            if(nums.size() == 1) return nums[0];
            if(nums.size() == 2) return max(nums[0], nums[1]);
            int choice1, choice2;
            int pre = nums[1], ppre = 0, cur;
            for(int i = 2; i < nums.size(); i++) {
                cur = max(pre, ppre + nums[i]);
                ppre = pre;
                pre = cur;
            }
            choice1 = cur;
            pre = nums[0], ppre = 0;
            for(int i = 1; i < nums.size() - 1; i++) {
                cur = max(pre, ppre + nums[i]);
                ppre = pre;
                pre = cur;
            }
            choice2 = cur;
            return max(choice1, choice2);
        }
    };