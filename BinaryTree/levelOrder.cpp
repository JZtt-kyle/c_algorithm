/* 
 * 题目: 二叉树的层序遍历
 * 功能描述: 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
 * 网址:https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
*/

#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}

class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            queue<TreeNode*> qu;
            vector<vector<int>> res;
            if(!root) return res;
            qu.push(root);
            while(!qu.empty()) {
                int size = qu.size();
                vector<int> vec;
                for(int i = 0; i < size; i++) {
                    TreeNode* tmp = qu.front();
                    qu.pop();
                    vec.push_back(tmp->val);
                    if(tmp->left) qu.push(tmp->left);
                    if(tmp->right) qu.push(tmp->right);
                }
                res.push_back(vec);
            }
            return res;
        }
    };