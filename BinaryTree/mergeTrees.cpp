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
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}

class Solution {
    public:
        TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
            if(!root1 && root2) {
                return root2;
            }
            if(root1 && !root2) {
                return root1;
            }
            if(!root1 && !root2) {
                return nullptr;
            }

            TreeNode* root = new TreeNode(root1->val + root2->val);

            root->left = mergeTrees(root1->left, root2->left);
            root->right = mergeTrees(root1->right, root2->right);
            return root;
        }
    };
