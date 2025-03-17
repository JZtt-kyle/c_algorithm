/* 
 * 题目: 把二叉搜索树转换为累加树
 * 功能描述: 给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。
 * 网址:https://leetcode.cn/problems/convert-bst-to-greater-tree/description/
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
        int sum = 0;
        TreeNode* convertBST(TreeNode* root) {
            traversal(root);
            return root;
        }
        void traversal(TreeNode* root) {
            if(!root) return;
            traversal(root->right);
            sum += root->val;
            root->val = sum;
            traversal(root->left);
        }
    };