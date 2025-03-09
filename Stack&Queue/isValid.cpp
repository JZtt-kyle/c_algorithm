/* 
 * 题目: 有效的括号
 * 功能描述: 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 网址:https://leetcode.cn/problems/valid-parentheses/description/
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> stack;
            for(int i = 0; i < s.length(); i++) {
                char c = s[i];
                if(!stack.empty()) {
                    if(c == ')' && stack.top() == '(') {
                        stack.pop();
                        continue;
                    }
                    if(c == ']' && stack.top() == '[') {
                        stack.pop();
                        continue;
                    }
                    if(c == '}' && stack.top() == '{') {
                        stack.pop();
                        continue;
                    }
                }
                stack.push(c);
            }
            return stack.empty();
        }
    };