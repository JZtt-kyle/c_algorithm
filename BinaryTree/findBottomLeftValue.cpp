/* 
 * 题目: 找树左下角的值
 * 功能描述: 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
假设二叉树中至少有一个节点。
 * 网址:https://leetcode.cn/problems/find-bottom-left-tree-value/description/
*/


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
        int findBottomLeftValue(TreeNode* root) {
            queue<TreeNode*> qu;
            qu.push(root);
            int res;
            while(!qu.empty()) {
                int size = qu.size();
                res = qu.front()->val;
                for(int i = 0; i < size; i++) {
                    TreeNode* t = qu.front();
                    qu.pop();
                    if(t->left) qu.push(t->left);
                    if(t->right) qu.push(t->right);
                }
            }
            return res;
        }
    };