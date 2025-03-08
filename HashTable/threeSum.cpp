/* 
 * 题目: 三数之和
 * 功能描述: 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
 * 网址:https://leetcode.cn/problems/3sum/description/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            sort(nums.begin(), nums.end());
            int length = nums.size();
            for(int i = 0; i < length; i++) {
                if(nums[i] > 0) break;
                if(i > 0 && nums[i] == nums[i - 1]) continue;
                int left = i + 1, right = length - 1;
                while(left < right) {
                    if(nums[i] + nums[left] + nums[right] == 0) {
                        result.push_back({nums[i], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left + 1]) left++;
                        while(left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    }else if(nums[i] + nums[left] + nums[right] > 0) {
                        right--;
                    }else {
                        left++;
                    }
                }
            }
            return result;
        }
    };
