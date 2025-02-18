/* 
 * 题目: 长度最小的子数组
 * 功能描述: 给定一个含有 n 个正整数的数组和一个正整数 target 。找出该数组中满足其总和大于等于 target 的长度最小的 子数组[numsl, num+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 * 网址:https://leetcode.cn/problems/minimum-size-subarray-sum/description/
*/

/* 
 * 滑动窗口维护数组和字符串中的区间，用于优化时间复杂度
 * 窗口的大小控制是关键，窗口的大小据具体情况而定，该题目中，左边界是当出现满足子数组总和大于等于target时向右移动，右边界每轮更新计算总和。 
*/

int minSubArrayLen(int target, int* nums, int numsSize) {
    int result = 0, i = 0, sum = 0;
    for(int j = 0; j < numsSize; j++){
        sum += nums[j];
        if(sum >= target){
            if(result == 0 || result > j - i + 1){
                result = j - i + 1;
            }
            sum = sum - nums[i++] - nums[j--];
        }
    }
    return result;
}