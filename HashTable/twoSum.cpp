/* 
 * 题目: 两数之和
 * 功能描述: 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
 * 网址:https://leetcode.cn/problems/two-sum/description/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> map;
            for(int i = 0; i < nums.size(); i++) {
                auto it = map.find(target - nums[i]);
                if(it != map.end()) return {it->second, i};
                else map.insert(pair<int, int>(nums[i], i));
            }
            return {};
        }
    };