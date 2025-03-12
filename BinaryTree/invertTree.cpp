/* 
 * 题目: 翻转二叉树
 * 功能描述: 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
 * 网址:https://leetcode.cn/problems/invert-binary-tree/description/
*/

#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}

class Solution {
    public:
        //递归法
        TreeNode* invertTree1(TreeNode* root) {
            if(!root) return root;
            swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
            return root;
        }
        //迭代法
        TreeNode* invertTree2(TreeNode* root) {
            stack<TreeNode*> st;
            if(!root) return root;
            st.push(root);
            while(!st.empty()) {
                TreeNode* t = st.top();
                st.pop();
                swap(t->left, t->right);
                if(t->right) st.push(t->right);
                if(t->left) st.push(t->left);
            }
            return root;
        }
    };