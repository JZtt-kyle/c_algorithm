/* 
 * 题目: 用队列实现栈
 * 功能描述: 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
 * 网址:https://leetcode.cn/problems/implement-queue-using-stacks/description/
*/

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    public:

        queue<int> q1;
        queue<int> q2;

        MyStack() {
            
        }
        
        void push(int x) {
            q2.push(x);
            while(!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
            swap(q1, q2);
        }
        
        int pop() {
            int res = q1.front();
            q1.pop();
            return res;
        }
        
        int top() {
           return q1.front();
        }
        
        bool empty() {
            return q1.empty();
        }
    };