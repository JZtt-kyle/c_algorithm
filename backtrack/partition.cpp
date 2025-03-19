/* 
 * 题目: 分割回文串
 * 功能描述: 给你一个字符串 s，请你将 s 分割成一些 子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 * 网址:https://leetcode.cn/problems/palindrome-partitioning/description/
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        vector<string> path; 
        vector<vector<string>> res;
        vector<vector<string>> partition(string s) {
            backtrack(s, 0);
            return res;
        }
        void backtrack(string s, int startIndex) {
            if(startIndex >= s.size()) {
                res.push_back(path);
                return;
            }
            for(int i = startIndex; i < s.size(); i++) {
                if(isPalindrome(s, startIndex, i + 1)) {
                    string str = s.substr(startIndex, i - startIndex + 1);
                    path.push_back(str);
                }else continue;
                backtrack(s, i + 1);
                path.pop_back();
            }
        }
        bool isPalindrome(string s, int start, int end) {
            int i = start; int j = end - 1;
            while(i <= j) {
                if(s[i] != s[j]) return false; 
                i++;
                j--;
            }
            return true;
        }
    };