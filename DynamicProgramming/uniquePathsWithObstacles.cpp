/* 
 * 题目: 不同路径 II
 * 功能描述: 给定一个 m x n 的整数数组 grid。一个机器人初始位于 左上角（即 grid[0][0]）。机器人尝试移动到 右下角（即 grid[m - 1][n - 1]）。机器人每次只能向下或者向右移动一步。
网格中的障碍物和空位置分别用 1 和 0 来表示。机器人的移动路径中不能包含 任何 有障碍物的方格。
返回机器人能够到达右下角的不同路径数量。
 * 网址:https://leetcode.cn/problems/unique-paths-ii/description/
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
            obstacleGrid[0][0] = 1;
            for(int i = 1; i < m; i++) {
                if(obstacleGrid[i][0] == 1) obstacleGrid[i][0] = 0;
                else obstacleGrid[i][0] = obstacleGrid[i - 1][0];
            }
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[0][j] == 1) obstacleGrid[0][j] = 0;
                else obstacleGrid[0][j] = obstacleGrid[0][j - 1];
            }
            for(int i = 1; i < m; i++) {
                for(int j = 1; j < n; j++) {
                    if(obstacleGrid[i][j] == 1) {
                        obstacleGrid[i][j] = 0;
                    } 
                    else {
                        obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                    }
                }
            }
            
            return obstacleGrid[m - 1][n - 1];
        }
    };