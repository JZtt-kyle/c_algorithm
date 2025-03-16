/* 
 * 题目: 合并二叉树
 * 功能描述: 给你两棵二叉树： root1 和 root2 。
想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，不为 null 的节点将直接作为新二叉树的节点。
返回合并后的二叉树。
 * 网址:https://leetcode.cn/problems/merge-two-binary-trees/description/
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
        TreeNode* searchBST(TreeNode* root, int val) {
            if(!root || root->val == val) return root;
            TreeNode* res = NULL;
            if(root->val > val) res = searchBST(root->left, val);
            if(root->val < val) res = searchBST(root->right, val);
            return res;
        }
    };