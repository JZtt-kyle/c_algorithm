/* 
 * 题目: 二叉树的最大深度
 * 功能描述: 给定一个二叉树 root ，返回其最大深度。
二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
 * 网址:https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
*/


#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}

class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if(!root) return 0;
            int left = maxDepth(root->left);
            int right = maxDepth(root->right);
            return max(left, right) + 1;
        }
    };
