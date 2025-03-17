/* 
 * 题目: 将有序数组转换为二叉搜索树
 * 功能描述: 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 平衡 二叉搜索树。
 * 网址:https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/
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
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            if(nums.size() == 0) return nullptr;
            int index = nums.size() / 2;
            TreeNode* root = new TreeNode(nums[index]);
            vector<int> left(nums.begin(), nums.begin() + index);
            vector<int> right(nums.begin() + index + 1, nums.end());
            root->left = sortedArrayToBST(left);
            root->right = sortedArrayToBST(right);
            return root;
        }
    };