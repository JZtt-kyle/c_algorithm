/* 
 * 题目: 链表相交
 * 功能描述: 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
 * 网址:https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/description/
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            int lengthA = 0;
            int lengthB = 0;
            ListNode *cur1 = headA;
            ListNode *cur2 = headB;
            while(cur1) {
                lengthA++;
                cur1 = cur1->next;
            }
            while(cur2) {
                lengthB++;
                cur2 = cur2->next;
            }
            cur1 = headA;
            cur2 = headB;
            int num = lengthA - lengthB;
            if(num >= 0) {
                for(int i = 0; i < num; i++) cur1 = cur1->next;
            }else {
                for(int i = num; i < 0; i++) cur2 = cur2->next;
            }
            while(cur1 && cur2){
                if(cur1 == cur2) return cur1;
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            return nullptr;
        }
    };