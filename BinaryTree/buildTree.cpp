/* 
 * 题目: 从中序与后序遍历序列构造二叉树
 * 功能描述: 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
 * 网址:https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
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
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            
        }
    };