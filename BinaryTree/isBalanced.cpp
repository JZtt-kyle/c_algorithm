/* 
 * 题目: 平衡二叉树
 * 功能描述: 给定一个二叉树，判断它是否是 平衡二叉树 
 * 网址:https://leetcode.cn/problems/balanced-binary-tree/description/
*/


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
        bool isBalanced(TreeNode* root) {
            return depth(root) != -1;
        }
        int depth(TreeNode* root) {
            if(!root) return 0;
            int left = depth(root->left);
            int right = depth(root->right);
            if(left == -1 || right == -1) return -1;
            if(abs(left - right) > 1) return -1;
            return max(left, right) + 1;
        }
    };