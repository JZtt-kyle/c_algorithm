/* 
 * 题目: 单词拆分
 * 功能描述: 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
 * 网址:https://leetcode.cn/problems/word-break/description/
*/

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            vector<bool> dp(s.size() + 1, false);
            unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
            dp[0] = true;
            for(int j = 1; j <= s.size(); j++) {
                for(int i = 0; i < j; i++) {
                    string word = s.substr(i, j - i);
                    if(wordSet.find(word) != wordSet.end() && dp[i]) {
                        dp[j] = true;
                    }
                }
            }
            return dp[s.size()];
        }
    };