/* 
 * 题目: 二分查找 
 * 功能描述: 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。 
 * 网址:https://leetcode.cn/problems/binary-search/description/
*/


int search(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize - 1;
    int mid;
    while(low <= high){
        mid = low + (high - low) / 2;
        if(nums[mid] == target){
            return mid;
        }else if (nums[mid] < target){
            low = mid + 1;
        }else if (nums[mid] > target){
            high = mid - 1;
        }
    }
    return -1;
}
