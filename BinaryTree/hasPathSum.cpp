/* 
 * 题目: 路径总和
 * 功能描述: 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。
叶子节点 是指没有子节点的节点。
 * 网址:https://leetcode.cn/problems/path-sum/description/
*/


using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}

class Solution {
    public:
        int flag = false;
        bool hasPathSum(TreeNode* root, int targetSum) {
            traversal(root, targetSum);
            return flag;
        }
        void traversal(TreeNode* root, int num) {
            if(!root) return;
            int val = root->val;
            if(!root->left && !root->right && val == num) flag = true;
            traversal(root->left, num - val);
            traversal(root->right, num - val);
        }
    };
