/* 
 * 题目: 完全二叉树的节点个数
 * 功能描述: 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层（从第 0 层开始），则该层包含 1~ 2h 个节点。
 * 网址:https://leetcode.cn/problems/count-complete-tree-nodes/description/
*/


#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}

class Solution {
    public:
        int countNodes(TreeNode* root) {
            if(!root) return 0;
            int left = countNodes(root->left);
            int right = countNodes(root->right);
            return left + right + 1;
        }
    };
