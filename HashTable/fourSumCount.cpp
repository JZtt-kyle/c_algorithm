/* 
 * 题目: 四数相加Ⅱ
 * 功能描述: 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 * 网址:https://leetcode.cn/problems/4sum-ii/description/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
            int length = nums1.size(), sum, result = 0;
            unordered_map<int, int> map;
            for(int i = 0; i < length; i++) {
                for(int j = 0; j < length; j++) {
                    sum = nums1[i] + nums2[j];
                    map[sum]++;
                }
            }
            for(int k = 0; k < length; k++) {
                for(int l = 0; l < length; l++) {
                    sum = nums3[k] + nums4[l];
                    if(map.find(0 - sum) != map.end()) result += map[0 - sum];
                }
            }
            return result;
        }
    };

