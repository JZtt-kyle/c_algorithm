/* 
 * 题目: 二叉树的所有路径
 * 功能描述: 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
叶子节点 是指没有子节点的节点。
 * 网址:https://leetcode.cn/problems/binary-tree-paths/description/
*/


#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}

class Solution {
    public:
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> res;
            traversal(root, res, "");
            return res;
        }
        void traversal(TreeNode* root, vector<string> &vec, string s) {
            if(!root) return;
            int val = root->val;
            if(s.empty()) s = s + to_string(val);
            else s = s + "->" + to_string(val);
            if(!root->left && !root->right) {
                vec.push_back(s);
                return;
            }
            traversal(root->left, vec, s);
            traversal(root->right, vec, s);
        }
    };
