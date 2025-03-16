/* 
 * 题目: 二叉搜索树的最小绝对差
 * 功能描述: 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
差值是一个正数，其数值等于两值之差的绝对值。
 * 网址:https://leetcode.cn/problems/validate-binary-search-tree/description/
*/

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        int res = 0x7fffffff;
        TreeNode* pre = nullptr;
        int getMinimumDifference(TreeNode* root) {
            traversal(root);
            return res;
        }
        void traversal(TreeNode* root) {
            if(!root) return;
            traversal(root->left);
            if(pre && root->val - pre->val < res) res = root->val - pre->val;
            pre = root;
            traversal(root->right);
        }
    };
