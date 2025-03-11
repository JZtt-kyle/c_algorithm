/* 
 * 题目: 前 K 个高频元素
 * 功能描述: 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 * 网址:https://leetcode.cn/problems/top-k-frequent-elements/description/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
    public:

        class mycomparison {
            public:
                bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
                    return lhs.second > rhs.second;
                }
            };
        vector<int> topKFrequent(vector<int>& nums, int k) {
            vector<int> res(k);
            unordered_map<int, int> map;
            for(int t : nums) {
                map[t]++;
            }
            priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_q;
            for(auto it = map.begin(); it != map.end(); it++) {
                pri_q.push(*it);
                if(pri_q.size() > k){
                    pri_q.pop();
                }
            }
            for (int i = k - 1; i >= 0; i--) {
                res[i] = pri_q.top().first;
                pri_q.pop();
            }    
            return res;
        }
    };

