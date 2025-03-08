/* 
 * 题目: 四数之和
 * 功能描述: 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] 
 * 网址:https://leetcode.cn/problems/4sum/description/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> result;
            int length = nums.size();
            sort(nums.begin(), nums.end());
            for(int i = 0; i < length; i++) {
                if(nums[i] > target && nums[i] >= 0) break;
                if(i > 0 && nums[i] == nums[i - 1]) continue;
                for(int j = i + 1; j < length; j++) {
                    if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) break;
                    if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                    int left = j + 1, right = length - 1;
                    while(left < right) {
                        if((long)nums[i] + nums[j] + nums[left] + nums[right] == target) {
                            result.push_back({nums[i], nums[j], nums[left], nums[right]});
                            while(left < right && nums[left] == nums[left + 1]) left++;
                            while(left < right && nums[right] == nums[right - 1]) right--;
                            left++;
                            right--;
                        }else if((long)nums[i] + nums[j] + nums[left] + nums[right] < target) { 
                            left++;
                        }else {
                            right--;
                        }
                    }
                }
            }
            return result;
        }
    };