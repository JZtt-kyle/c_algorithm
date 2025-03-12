/* 
 * 题目: 二叉树的后序遍历
 * 功能描述: 给你二叉树的根节点 root ，返回它节点值的 后序 遍历。
 * 网址:https://leetcode.cn/problems/binary-tree-postorder-traversal/
*/

#include <vector>
#include <stack>
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
        //递归法
        vector<int> postorderTraversal1(TreeNode* root) {
            vector<int> res;
            postorder(root, res);
            return res;
        }
        //迭代法
        vector<int> postorderTraversal2(TreeNode* root) {
            stack<TreeNode*> st;
            vector<int> res;
            if(!root) return res;
            st.push(root);
            while(!st.empty()) {
                TreeNode* tmp = st.top();
                st.pop();
                res.push_back(tmp->val);
                //后序遍历要在前序的基础上交换入栈顺序，最后再反转
                if(tmp->left) st.push(tmp->left);
                if(tmp->right) st.push(tmp->right);
            }
            reverse(res.begin(), res.end());
            return res;
        }
        void postorder(TreeNode* root, vector<int> &vec) {
            if(!root) return;
            postorder(root->left, vec);
            postorder(root->right, vec);
            vec.push_back(root->val);
        }
    };