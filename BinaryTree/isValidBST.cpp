/* 
 * 题目: 验证二叉搜索树
 * 功能描述: 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
有效 二叉搜索树定义如下：
节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
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
        TreeNode* pre = nullptr;
        bool isValidBST(TreeNode* root) {
            if(!root) return true;

            bool left = isValidBST(root->left);

            if(pre && pre->val >= root->val) return false;
            pre = root;

            bool right = isValidBST(root->right);

            return left && right;
        }

    };