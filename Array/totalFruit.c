/* 
 * 题目: 水果成篮
 * 功能描述: 你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组 fruits 表示，其中 fruits[i] 是第 i 棵树上的水果 种类 。
你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：
你只有 两个 篮子，并且每个篮子只能装 单一类型 的水果。每个篮子能够装的水果总量没有限制。
你可以选择任意一棵树开始采摘，你必须从 每棵 树（包括开始采摘的树）上 恰好摘一个水果 。采摘的水果应当符合篮子中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘。
一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。
给你一个整数数组 fruits ，返回你可以收集的水果的 最大 数目。
 * 网址:https://leetcode.cn/problems/fruit-into-baskets/description/
*/

/* 
 * 仍然是滑动窗口的问题
 * 本题重点仍是窗口边界的变动，也就是左边界在什么时候变动，显然当子数组中有三种水果时就应该修改左边界。可以用kinds变量记录当前的水果种类数，用count[i]记录种类i的水果总共有多少个。当遇到count[j]=0时，kinds加1。当kinds大于2时，左边界向右移动，同时count[left]减1直到count[left]=0，kinds就减1，此时左边界才停止移动。
*/

int totalFruit(int* fruits, int fruitsSize) {
    int result = 0, i = 0, kinds = 0;
    int* count = (int*)malloc(fruitsSize * sizeof(int));
    for(int k =  0; k < fruitsSize; k++){
        count[k] = 0;
    }
    for(int j = 0; j < fruitsSize; j++){
        if(count[fruits[j]] == 0){
            kinds++;
        }
        count[fruits[j]]++;
       while(kinds > 2){
            count[fruits[i]]--;
            if(count[fruits[i]] == 0){
                kinds--;
            }
            i++;
       }
       if(j - i + 1 > result){
            result = j - i + 1;
       } 
    }
    return result;
}