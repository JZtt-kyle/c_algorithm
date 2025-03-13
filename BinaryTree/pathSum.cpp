/* 
 * 题目: 路径总和Ⅱ
 * 功能描述: 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
叶子节点 是指没有子节点的节点。
 * 网址:https://leetcode.cn/problems/path-sum-ii/description/
*/


#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}

class Solution {
    public:
        vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            vector<vector<int>> res;
            vector<int> path;
            if(!root) return res;
            traversal(root, path, res, targetSum);
            return res;
        }
        void traversal(TreeNode* root, vector<int> &path, vector<vector<int>> &res, int num) {
            int val = root->val;
            path.push_back(val);
            if(!root->left && !root->right && num == val) {
                res.push_back(path);
            }
            if(root->left) {
                traversal(root->left, path, res, num - val);
                path.pop_back();
            }
            if(root->right) {
                traversal(root->right, path, res, num - val);
                path.pop_back();
            }
        }
    };