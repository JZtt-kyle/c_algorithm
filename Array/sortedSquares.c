/* 
 * 题目: 有序数组的平方
 * 功能描述: 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 * 网址:https://leetcode.cn/problems/squares-of-a-sorted-array/description/
*/

/* 
 * 双指针法，指针从数组两端像中间移动，用于搜索、排序、合并。
 * 此题就是比较两个指针的平方数的大小（注意有序，两端的平方数大于中间的平方数），然后合并，与归并排序又异曲同工之妙。
*/
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    * returnSize = numsSize;
    int* result = (int*)malloc(sizeof(int) * numsSize);
    int i = 0, j = numsSize - 1, index = numsSize - 1;
    while(i <= j){
        if(nums[i] * nums[i] < nums[j] * nums[j]){
            result[index--] = nums[j] * nums[j];
            j--;
        }else{
            result[index--] = nums[i] * nums[i];
            i++;
        }
    }
    return result;
}