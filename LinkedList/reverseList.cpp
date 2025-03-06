/* 
 * 题目: 反转链表 
 * 功能描述: 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 * 网址:https://leetcode.cn/problems/reverse-linked-list/description/
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <iostream>
using namespace std;

class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode *tmp = nullptr;
            ListNode *pre = nullptr;
            ListNode *cur = head;
            while(cur){
               tmp = cur->next;
               cur->next = pre;
               pre = cur;
               cur = tmp;
            }
            return pre;
        }
    };