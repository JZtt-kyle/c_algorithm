/* 
 * 题目: 用栈实现队列
 * 功能描述: 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）
 * 网址:https://leetcode.cn/problems/implement-queue-using-stacks/description/
*/

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {

    stack<int> s1;
    stack<int> s2;

    public:
        MyQueue() {
            
        }
        
        void push(int x) {
            s1.push(x);
        }
        
        int pop() {
            if(s2.empty()) {
                while(!s1.empty()) {
                    int t = s1.top();
                    s2.push(t);
                    s1.pop();
                }
            }
            int res = s2.top();
            s2.pop();
            return res;
        }
        
        int peek() {
            int res = this->pop();
            s2.push(res);
            return res;
        }
        
        bool empty() {
            return s1.empty() && s2.empty();
        }

    };