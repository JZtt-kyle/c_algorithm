/* 
 * 题目: 赎金信
 * 功能描述: 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
如果可以，返回 true ；否则返回 false 。
 * 网址:https://leetcode.cn/problems/ransom-note/description/
*/

#include <iostream>
using namespace std;

class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            int record[26] = {0};
            int length1 = magazine.size();
            int length2 = ransomNote.size();
            if(length2 > length1) return false;
            for(int i = 0; i < length1; i++) record[magazine[i] - 'a']++;
            for(int j = 0; j < length2; j++) {
                if(--record[ransomNote[j] - 'a'] < 0) return false;
            }
            return true;
        }
    };