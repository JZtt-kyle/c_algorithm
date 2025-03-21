/* 
 * 题目: 0-1背包
 * 功能描述: 有n件物品和一个最多能背重量为w 的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。每件物品只能用一次，求解将哪些物品装入背包里物品价值总和最大。
 * 网址:https://kamacoder.com/problempage.php?pid=1046
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int bag0_1(int bagWeight, vector<int> weight, vector<int> value) {
            vector<int> dp(bagWeight + 1);
            for(int i = 0; i < weight.size(); i++) {
                for(int j = bagWeight; j >= weight[i]; j--) {
                    dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
                }
            }
            return dp[bagWeight];
        }
    };