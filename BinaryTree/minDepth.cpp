/* 
 * 题目: 二叉树的最小深度
 * 功能描述: 给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明：叶子节点是指没有子节点的节点。
 * 网址:https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
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
        int minDepth(TreeNode* root) {
            if(!root) return 0;
            int left = minDepth(root->left);
            int right = minDepth(root->right);

            if(root->left && !root->right) return left + 1;
            if(!root->left && root->right) return right + 1;

            return min(left, right) + 1;
        }
    };