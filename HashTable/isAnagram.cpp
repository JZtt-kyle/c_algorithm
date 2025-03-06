/* 
 * 题目: 有效的字母异位词
 * 功能描述: 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。
 * 网址:https://leetcode.cn/problems/valid-anagram/description/
*/

#include <iostream>
using namespace std;

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.length() != t.length()) return false;
            int length = s.length();
            int record[26] = {0};
            for(int i = 0; i < length; i++) {
                record[s[i]-'a']++;
            }
            for(int i = 0; i < length; i++) {
                record[t[i]-'a']--;
            }
            for(int i = 0; i < 26; i++) {
                if(record[i] != 0) return false;
            }
            return true;
        }
    };