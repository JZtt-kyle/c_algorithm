/* 
 * 题目: 二叉搜索树中的众数
 * 功能描述: 给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
如果树中有不止一个众数，可以按 任意顺序 返回。
 * 网址:https://leetcode.cn/problems/find-mode-in-binary-search-tree/
*/
#include <vector>
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
        int countMax = 1;
        int count = 1;
        int base = 100001;
        vector<int> res;
        vector<int> findMode(TreeNode* root) {
            traversal(root);
            return res;
        }
        void traversal(TreeNode* root) {
            if(!root) return;
            traversal(root->left);
            int val = root->val;
            if(base == val) {
                count++;
            }else {
                count = 1;
                base = val;
            }
            if(count == countMax) res.push_back(val);
            if(count > countMax) {
                countMax = count;
                res = vector<int>{base};
            }
            traversal(root->right);
        }
    };