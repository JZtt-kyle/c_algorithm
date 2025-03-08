/* 
 * 题目: 重复的子字符串
 * 功能描述: 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
 * 网址:https://leetcode.cn/problems/repeated-substring-pattern/description/
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        bool repeatedSubstringPattern(string s) {
            int len = s.size();
            for(int i = 1; i <= len / 2; i++) {
                if(len % i != 0) continue;
                int j;
                int k = 0;
                for(j = i; j < len; j++) {
                    if(s[k] != s[j])  break;
                    k = (k + 1) % i;
                }
                if(j == len) return true;
            }
            return false;
        }
    };
