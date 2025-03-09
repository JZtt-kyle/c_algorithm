/* 
 * 题目: 删除字符串中的所有相邻重复项
 * 功能描述: 给出由小写字母组成的字符串 s，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
在 s 上反复执行重复项删除操作，直到无法继续删除。
在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
 * 网址:https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
    public:
        string removeDuplicates(string s) {
            stack<char> stack;
            for(int i = 0; i < s.length(); i++) {
                char c = s[i];
                if(!stack.empty() && stack.top() == c) {
                    stack.pop();
                    continue;
                }
                stack.push(c);
            }
            int size = stack.size();
            s.resize(size);
            for(int j = size - 1; j >= 0; j--) {
                s[j] = stack.top();
                stack.pop();
            }
            return s;
        }
    };