/* 
 * 题目: 重新安排行程
 * 功能描述: 给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。
所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。
 * 网址:https://leetcode.cn/problems/reconstruct-itinerary/description/
*/

#include <vector>
#include <string>
using namespace std;
//回溯超时或者爆内存
class Solution {
    public:
        vector<string> path;
        vector<vector<string>> res;
        vector<int> used = vector<int>(300, 0);
        vector<string> findItinerary(vector<vector<string>>& tickets) {
            path.push_back("JFK");
            backtrack(tickets, "JFK");
            if(res.size() == 1) return res[0];
            else {
                vector<string> min = res[0];
                for(auto vec : res) {
                    if(vec < min) min = vec;
                }
                return min;
            }
            
        }
        void backtrack(vector<vector<string>>& tickets, string point) {
            if(path.size() == tickets.size() + 1) {
                res.push_back(path);
                return;
            }
            for(int i = 0; i < tickets.size(); i++) {
                if(used[i] == 1) continue;
                if(tickets[i][0] == point) {
                    string s = tickets[i][1];
                    used[i] = 1;
                    path.push_back(s);
                    backtrack(tickets, s);
                    path.pop_back();
                    used[i] = 0;
                }else continue;
            }
        }
    };