/* 
 * 题目: 螺旋矩阵II
 * 功能描述: 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 * 网址:https://leetcode.cn/problems/spiral-matrix-ii/description/
*/

/* 
 * 傻逼题，画图照着写
*/

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    int ** maxtrix = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
        maxtrix[i] = (int*)malloc(n * sizeof(int));
    }
    int num = 1;
    for(int t = 0; t < n/2; t++){
        for(int i = t; i < n - t - 1; i++){
            maxtrix[t][i] = num++;
        }
        for(int j = t; j < n - t - 1; j++){
            maxtrix[j][n - t - 1] = num++;
        }
        for(int k = t; k < n - t - 1; k++){
            maxtrix[n - t - 1][n - k - 1] = num++;
        }
        for(int m = t; m < n - t - 1; m++){
            maxtrix[n - m - 1][t] = num++;
        }
       
    }
    if(n % 2 != 0){
        maxtrix[n / 2][n / 2] = num;
    }
    return maxtrix;
}