/* 
 * 题目: 二叉搜索树中的插入操作
 * 功能描述: 给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value ，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。
注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 任意有效的结果 。
 * 网址:https://leetcode.cn/problems/insert-into-a-binary-search-tree/description/
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
        TreeNode* insertIntoBST(TreeNode* root, int val) {
            if(!root) {
                TreeNode* node = new TreeNode(val);
                return node;
            }
            if(root->val < val) root->right = insertIntoBST(root->right, val);
            if(root->val > val) root->left = insertIntoBST(root->left, val);
            return root;
        }
    };