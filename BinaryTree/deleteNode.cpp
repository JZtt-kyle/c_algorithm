/* 
 * 题目: 删除二叉搜索树中的节点
 * 功能描述: 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
一般来说，删除节点可分为两个步骤：
首先找到需要删除的节点；
如果找到了，删除它。
 * 网址:https://leetcode.cn/problems/delete-node-in-a-bst/description/
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
        TreeNode* deleteNode(TreeNode* root, int key) {
            if(!root) return root;
            if(root->val == key) {
                if(!root->left && !root->right) {
                    delete root;
                    return nullptr;
                }else if(!root->left) {
                    TreeNode* node = root->right;
                    delete root;
                    return node;
                }else if(!root->right) {
                    TreeNode* node = root->left;
                    delete root;
                    return node;
                }else {
                    TreeNode* cur = root->right;
                    while(cur->left){
                        cur = cur->left;
                    }
                    cur->left = root->left;
                    TreeNode* tmp = root;
                    root = root->right;
                    delete tmp;
                    return root;
                }
            }
            if(root->val < key) root->right = deleteNode(root->right, key);
            if(root->val > key) root->left = deleteNode(root->left, key);
            return root;
        }
    };