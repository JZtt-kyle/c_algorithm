/* 
 * 题目: 两个数组的交集
 * 功能描述: 给定两个数组 nums1 和 nums2 ，返回 它们的 交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
 * 网址:https://leetcode.cn/problems/intersection-of-two-arrays/description/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            vector<int> result;
            int record[1001] = {0};
            for(int t : nums1) {
                record[t]++;
            }
            for(int t : nums2) {
                if(record[t] != 0) result.push_back(t);
            }
            sort(result.begin(), result.end());
            auto last = unique(result.begin(), result.end());
            result.erase(last, result.end());
            return result;
        }
    };