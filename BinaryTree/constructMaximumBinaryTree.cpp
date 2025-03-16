/* 
 * 题目: 最大二叉树
 * 功能描述: 给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:
创建一个根节点，其值为 nums 中的最大值。
递归地在最大值 左边 的 子数组前缀上 构建左子树。
递归地在最大值 右边 的 子数组后缀上 构建右子树。
返回 nums 构建的 最大二叉树 。
 * 网址:https://leetcode.cn/problems/maximum-binary-tree/description/
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
        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            if(nums.size() == 0) return nullptr;
            int index = 0;
            for(int i = 1; i < nums.size(); i++) {
                if(nums[index] < nums[i]) index = i;
            }
            TreeNode* root = new TreeNode(nums[index]);
            vector<int> left(nums.begin(), nums.begin() + index);
            vector<int> right(nums.begin() + index + 1, nums.end());

            root->left = constructMaximumBinaryTree(left);
            root->right = constructMaximumBinaryTree(right);
            return root;
        }
    };