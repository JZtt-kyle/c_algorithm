/* 
 * 题目: 电话号码的字母组合
 * 功能描述: 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 网址:https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        string path;
        vector<string> res;
        vector<string> f = {"abc", "def", "ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> letterCombinations(string digits) {
            if(digits.empty()) return vector<string>{};
            backtrack(digits, 0);
            return res;
        }
        void backtrack(string digits, int index) {
            if(path.size() == digits.size()) {
                res.push_back(path);
                return;
            }
            string s = f[digits[index] - '2'];
            for(int i = 0; i < s.size(); i++) {
                path.push_back(s[i]);
                backtrack(digits, index + 1);
                path.pop_back();
            }
        }
    };