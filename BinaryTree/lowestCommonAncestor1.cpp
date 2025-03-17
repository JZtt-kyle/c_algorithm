/* 
 * 题目: 二叉搜索树的最近公共祖先
 * 功能描述: 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 网址:https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
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
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root->val > q->val && root->val > p->val) return lowestCommonAncestor(root->left, p, q);
            if(root->val < q->val && root->val < p->val) return lowestCommonAncestor(root->right, p, q);
            return root;
        }
    };
