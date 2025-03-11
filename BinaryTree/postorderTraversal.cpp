/* 
 * 题目: 二叉树的后序遍历
 * 功能描述: 给你二叉树的根节点 root ，返回它节点值的 后序 遍历。
 * 网址:https://leetcode.cn/problems/binary-tree-postorder-traversal/
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
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> res;
            postorder(root, res);
            return res;
        }
        void postorder(TreeNode* root, vector<int> &vec) {
            if(!root) return;
            postorder(root->left, vec);
            postorder(root->right, vec);
            vec.push_back(root->val);
        }
    };