/* 
 * 题目: 左叶子之和
 * 功能描述: 给定二叉树的根节点 root ，返回所有左叶子之和。
 * 网址:https://leetcode.cn/problems/sum-of-left-leaves/description/
*/


#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}

class Solution {
    public:
        int sumOfLeftLeaves(TreeNode* root) {
            int sum = 0;
            traversal(root, sum);
            return sum;
        }

        void traversal(TreeNode* root, int &sum) {
            if(!root) return;
            if(root->left && !root->left->left && !root->left->right) {
                sum += root->left->val;
            }
            traversal(root->left, sum);
            traversal(root->right, sum);
        }
    };