/* 
 * 题目: 二叉树的中序遍历
 * 功能描述: 给你二叉树的根节点 root ，返回它节点值的 中序 遍历。
 * 网址:https://leetcode.cn/problems/binary-tree-inorder-traversal/
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
        vector<int> inorderTraversal1(TreeNode* root) {
            vector<int> res;
            inorder(root, res);
            return res;
        }
        //迭代法
        vector<int> inorderTraversal2(TreeNode* root) {
            stack<TreeNode*> st;
            vector<int> res;
            if(!root) return res;
            TreeNode* cur = root;
            while(cur || !st.empty()) {
                while(cur) {
                    st.push(cur);
                    cur = cur->left;
                }

                cur = st.top();
                st.pop();
                res.push_back(cur->val);

                cur = cur->right;
            }
            return res;
        }
        void inorder(TreeNode* root, vector<int> &vec) {
            if(!root) return;
            inorder(root->left, vec);
             vec.push_back(root->val);
            inorder(root->right, vec);
        }
    };