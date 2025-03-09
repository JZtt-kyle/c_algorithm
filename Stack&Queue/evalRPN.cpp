/* 
 * 题目: 逆波兰表达式求值
 * 功能描述: 给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。
请你计算该表达式。返回一个表示表达式值的整数。
 * 网址:https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> stack;
            for(string s : tokens) {
                if(s == "+" || s == "-" || s == "*" || s == "/") {
                    int num1 = stack.top();
                    stack.pop();
                    int num2 = stack.top();
                    stack.pop();
                    int res;
                    if(s == "+") res = num2 + num1;
                    if(s == "-") res = num2 - num1;
                    if(s == "*") res = num2 * num1;
                    if(s == "/") res = num2 / num1;
                    stack.push(res);
                }else {
                    stack.push(stoi(s));
                }
            }
            return stack.top();
        }
    };