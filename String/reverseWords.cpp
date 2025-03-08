/* 
 * 题目: 反转字符串中的单词
 * 功能描述: 给你一个字符串 s ，请你反转字符串中 单词 的顺序。
单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
 * 网址:https://leetcode.cn/problems/reverse-words-in-a-string/description/
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        string reverseWords(string s) {
            // int i = 0;
            // while(i < s.size() && s[i] == ' ') i++;
            // if(i != 0) s = s.substr(i);

            // int length1 = s.size();
            // i = length1 - 1;
            // while(i >= 0 && s[i] == ' ') i--;
            // if(i != length1 - 1) s = s.substr(0, i + 1);

            
            // int slow =0;
            // int length2 = s.size();
            // for(int fast = 0; fast < length2; fast++) {
            //     if(s[fast] != ' ' || s[fast] != s[fast - 1]) {
            //         s[slow++] = s[fast];
            //     }
            // }
            // s = s.substr(0, slow);

            int slow = 0;
            for(int fast = 0; fast < s.size(); fast++) {
                if(s[fast] != ' ') {
                    if(slow != 0) s[slow++] = ' ';
                    while(fast < s.size() && s[fast] != ' ') {
                        s[slow++] = s[fast++];
                    }
                }
            }
            s.resize(slow);

            int left = 0, right = 0;
            while(right < s.size()) {
                while(right < s.size() && s[right] != ' ') right++;
                reverse(s.begin() + left, s.begin() + right);
                left = right + 1;
                right++;
            }
            reverse(s.begin(), s.end());
            return s;
        }
    };