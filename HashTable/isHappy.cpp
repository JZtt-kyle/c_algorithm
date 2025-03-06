/* 
 * 题目: 快乐树
 * 功能描述: 编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
 * 网址:https://leetcode.cn/problems/happy-number/description/
*/

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
    public:

        //哈希表法
        bool isHappy(int n) {
            if(n == 1) return true;
            unordered_set<int> set;
            while(true) {
                n = squareSum(n);
                if(n == 1) return true;
                if(set.find(n) != set.end()) return false;
                else set.insert(n);
            }
        }
        //快慢指针法
        bool isHappy(int n) {
            int fast = n, slow = n;
            while(true) {
                fast = squareSum(squareSum(fast));
                slow = squareSum(slow);
                if(fast == 1 || slow == 1) return true;
                if(fast == slow) return false;
            }
        }

        int squareSum(int x) {
            int tmp;
            int sum = 0;
            while(x){
                tmp = x % 10;
                sum += tmp * tmp;
                x /= 10;
            }
            return sum;
        }
    };