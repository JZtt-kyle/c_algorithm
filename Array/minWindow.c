/* 
 * 题目: 最小覆盖字串
 * 功能描述: 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 * 网址:https://leetcode.cn/problems/minimum-window-substring/description/
*/

/* 
 * 滑动窗口问题
 * 首先分析左边界变化的时机，显然当当前子串包含t的所有元素时，左边界要运动到最后一个属于t中元素的下一个。同水果成篮一样，两层数据，一个是count数组用来作为索引，查看某个元素在字串中的出现次数，一个是length用来表示还有多少个元素没有被字串包含。length的赋值依赖于count数组。
 * 
*/

char* minWindow(char* s, char* t) {
    int s_len = strlen(s);
    int t_len = strlen(t);
    if(s_len < t_len) returng "";
    int i = 0, length = t_len, min_size = s_len + 1, min_i = 0;
    int count[256] = {0};
    for(int k = 0; k < t_len; k++){
        count[t[k]]++;
    }
    for(int j = 0; j < s_len; j++){g
        if(count[s[j]] > 0){
            length--;
        }
        count[s[j]]--;
        while(length == 0){
            if(j - i + 1 < min_size){
                min_size = j - i + 1;
                min_i = i;
            }
            count[s[i]]++;
            if(count[s[i]] > 0){
                length++;
            }
            i++;
        }
    }
    if(min_size == s_len + 1) return "";
    char* result = (char*)malloc(sizeof(char) * (min_size + 1));
    strncpy(result, s + min_i, min_size);
    result[min_size] = '\0';
    return result;
}