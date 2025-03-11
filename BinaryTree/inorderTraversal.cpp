/* 
 * 题目: 二叉树的中序遍历
 * 功能描述: 给你二叉树的根节点 root ，返回它节点值的 中序 遍历。
 * 网址:https://leetcode.cn/problems/binary-tree-inorder-traversal/
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
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            inorder(root, res);
            return res;
        }
        void inorder(TreeNode* root, vector<int> &vec) {
            if(!root) return;
            inorder(root->left, vec);
             vec.push_back(root->val);
            inorder(root->right, vec);
        }
    };