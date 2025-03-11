/* 
 * 题目: 二叉树的前序遍历
 * 功能描述: 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 * 网址:https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
*/

#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}

class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> res;
            traver(root, res);
            return res;
        }

        void preorder(TreeNode* root, vector<int> &vec) {
            if(!root) return;
            vec.push_back(root->val);
            traver(root->left, vec);
            traver(root->right, vec);
        }
    };