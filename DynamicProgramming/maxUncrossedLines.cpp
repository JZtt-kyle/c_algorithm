/* 
 * 题目: 不相交的线
 * 功能描述: 在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。
现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足：
 nums1[i] == nums2[j]
且绘制的直线不与任何其他连线（非水平线）相交。
请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。
以这种方法绘制线条，并返回可以绘制的最大连线数。
 * 网址:https://leetcode.cn/problems/uncrossed-lines/description/
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
            int len1 = nums1.size(), len2 = nums2.size();
            vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
            for(int i = 1; i <= len1; i++) {
                for(int j = 1; j <= len2; j++) {
                    if(nums1[i - 1] == nums2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }else {
                        dp[i][j] = max(dp[i- 1][j], dp[i][j - 1]);
                    }
                }
            }
            return dp[len1][len2];
        }
    };