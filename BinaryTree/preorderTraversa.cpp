/* 
 * 题目: 二叉树的前序遍历
 * 功能描述: 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 * 网址:https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
*/

#include <vector>
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
        vector<int> preorderTraversal1(TreeNode* root) {
            vector<int> res;
            traver(root, res);
            return res;
        }
        //迭代法
        vector<int> preorderTraversal2(TreeNode* root) {
            stack<TreeNode*> st;
            vector<int> res;
            if(!root) return res;
            st.push(root);
            while(!st.empty()) {
                TreeNode* tmp = st.top();
                st.pop();
                res.push_back(tmp->val);
                //先放右子树，再放左子树
                if(tmp->right) st.push(tmp->right);
                if(tmp->left) st.push(tmp->left);
            }
            return res;
        }

        void preorder(TreeNode* root, vector<int> &vec) {
            if(!root) return;
            vec.push_back(root->val);
            traver(root->left, vec);
            traver(root->right, vec);
        }
    };