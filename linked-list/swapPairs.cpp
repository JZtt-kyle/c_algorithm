/* 
 * 题目: 两两交换链表中的节点
 * 功能描述: 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
 * 网址:https://leetcode.cn/problems/swap-nodes-in-pairs/description/
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
        ListNode* swapPairs(ListNode* head) {
            if(!head || !head->next) return head;
            ListNode *dummyHead = new ListNode(0);
            dummyHead->next = head;
            ListNode *cur = dummyHead;
            while(cur->next && cur->next->next){
                ListNode *tmp1 = cur->next;
                ListNode *tmp2 = cur->next->next;
                cur->next = tmp2;
                tmp1->next = tmp2->next;
                tmp2->next = tmp1;

                cur = cur->next->next;
            }
            ListNode *result = dummyHead->next;
            delete dummyHead;
            return result;
        }
    };