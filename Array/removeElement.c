/* 
 * 题目: 移除元素 
 * 功能描述: 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。 
 * 网址:https://leetcode.cn/problems/remove-element/description/
*/

/*  
 * 测试不通过，末尾元素为val时，会产生死循环
 * 暴力解法，外循环遍历寻找元素val，内循环覆盖
*/
int removeElement1(int* nums, int numsSize, int val) {
    
    int result = numsSize;
    for (int i = 0; i < numsSize; i++){
        if(nums[i] == val){
            for (int j = i; j < numsSize - 1; j++){
                nums[j] = nums[j + 1];
            }
            i--;
            result--;
        }
    }
    return  result;
}

/*  
 * 快慢指针法，性能较高，适用于数组去重，移除元素，判断链表是否有环，寻找链表的中点
 * 快指针:遍历数组，寻找赋值元素，该题为非val元素
 * 慢指针:指向需要更新的位置
*/
int removeElement2(int* nums, int numsSize, int val) {
    int  slow = 0;
    for(int fast = 0; fast < numsSize; fast++){
        if(nums[fast] != val){
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}