/* 
 * 题目: N皇后
 * 功能描述: 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * https://leetcode.cn/problems/n-queens/description/
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        vector<vector<string>> res;
        vector<vector<string>> solveNQueens(int n) {
            vector<string> ans(n, string(n, '.'));
            backtrack(n, 0, ans);
            return res;
        }

        void backtrack(int n, int row, vector<string>& ans) {
            if(row == n) {
                res.push_back(ans);
                return;
            }
            for(int i = 0; i < n; i++) {
                if(isValid(row, i, ans, n)) {
                    ans[row][i] = 'Q';
                    backtrack(n, row + 1, ans);
                    ans[row][i] = '.';
                }
            }
        }

        bool isValid(int row, int col, vector<string>& chessboard, int n) {

            //列有效
            for(int i = 0; i < n; i++) {
                if(chessboard[i][col] == 'Q') return false;
            }

            //45度
            for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
                if(chessboard[i][j] == 'Q') return false;
            }
            
            //135度
            for(int i = row - 1, j = col - 1; i >= 0 && j>= 0; i--, j--) {
                if(chessboard[i][j] == 'Q') return false;
            }

            return true;
        }
    };
