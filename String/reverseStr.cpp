/* 
 * 题目: 反转字符串Ⅱ
 * 功能描述: 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 * 网址:https://leetcode.cn/problems/reverse-string-ii/description/
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        string reverseStr(string s, int k) {
            int i = 0;
            int length = s.length();
            while(i < length) {
                if(length - i < k) {
                    reverseByIndex(s, i, length);
                }else {
                    reverseByIndex(s, i, i + k);
                }
                i += 2*k;
            }
            return s;
        }

        string reverseByIndex(string &s, int begin, int end) {
            int i = begin, j = end - 1;
            while(i < j) {
                char t = s[i];
                s[i] = s[j];
                s[j] = t;
                i++;
                j--;
            }
            return s;
        }
    };