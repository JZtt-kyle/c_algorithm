/* 
 * 题目: 滑动窗口最大值
 * 功能描述: 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回 滑动窗口中的最大值 。
 * 网址:https://leetcode.cn/problems/sliding-window-maximum/description/
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class MyQueue {
    public:

        deque<int> d;

        void push(int x) {
            while(!d.empty() && d.back() < x) {
                d.pop_back();
            }
            d.push_back(x);
        }

        void pop(int x) {
            if(d.front() == x) {
                d.pop_front();
            }

        }
        int front() {
            return d.front();
        }

};

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> res;
            MyQueue* q = new MyQueue();
            for(int i = 0; i < k; i++) q->push(nums[i]);
            res.push_back(q->front());
            for(int j = k; j < nums.size(); j++) {
                q->pop(nums[j - k]);
                q->push(nums[j]);
                res.push_back(q->front());
            }
            return res;
        }
    };