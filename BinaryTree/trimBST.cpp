/* 
 * 题目: 修剪二叉搜索树
 * 功能描述: 给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。通过修剪二叉搜索树，使得所有节点的值在[low, high]中。修剪树 不应该 改变保留在树中的元素的相对结构 (即，如果没有被移除，原有的父代子代关系都应当保留)。 可以证明，存在 唯一的答案 。
所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。
 * 网址:https://leetcode.cn/problems/trim-a-binary-search-tree/description/
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
        TreeNode* trimBST(TreeNode* root, int low, int high) {
            if(!root) return root;
            if(root->val < low) return trimBST(root->right, low , high);
            if(root->val > high) return trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            root->left = trimBST(root->left, low, high);
            return root;
        }
    };

