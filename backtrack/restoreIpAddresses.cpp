/* 
 * 题目: 复原IP地址
 * 功能描述: 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
 * 网址:https://leetcode.cn/problems/restore-ip-addresses/description/
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        vector<string> res;
        vector<string> restoreIpAddresses(string s) {
            backtrack(s, 0, 0);
            return res;
        }
        void backtrack(string &s, int startIndex, int count) {
            if(count == 3) {
                if(isvalid(s.substr(startIndex, s.size() - startIndex)))
                res.push_back(s);
                return;
            }
            for(int i = startIndex; i < s.size(); i++) {
                if(isvalid(s.substr(startIndex, i - startIndex + 1))) {
                    s.insert(s.begin() + i + 1, '.');
                    backtrack(s, i + 2, count + 1);
                    s.erase(s.begin() + i + 1);
                }else break;
            }
        }

        bool isvalid(string str) {
            if(str.size() == 0) return false;
            if(str.size() > 1 && str[0] == '0') return false;
            if(stoll(str) > 255) return false;
            return true;
        }
    };