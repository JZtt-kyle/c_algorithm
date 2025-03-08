/* 
 * 题目: 找出字符串中第一个匹配项的下标
 * 功能描述: 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
 * 网址:https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        int strStr(string haystack, string needle) {
            int* next = getNext(needle);
            int j = 0;
            int len1 = haystack.size(), len2 = needle.size();
            for(int i = 0; i < len1; i++) {
                while(j > 0 && haystack[i] != needle[j]) {
                    j = next[j - 1];
                }
                if(haystack[i] == needle[j]) {
                    j++;
                }
                if(j == len2) {
                    return i - len2 + 1;
                }
            }
            return -1;
        }

        int* getNext(string s) {
            int len = s.size();
            int* next = new int[len]();
            int j = 0;
            for(int i = 1; i < len; i++) {
               while(j > 0 && s[i] != s[j]) {
                    j = next[j - 1];
               }
               if(s[i] == s[j]) {
                    next[i] = ++j;
               }
            }
            return next;
        }
    };