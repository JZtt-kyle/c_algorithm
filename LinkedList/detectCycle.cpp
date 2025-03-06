/* 
 * 题目: 两两交换链表中的节点
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
        ListNode *detectCycle(ListNode *head) {
            ListNode *index = head;
            ListNode *fast = head;
            ListNode *slow = head;
            while(fast && fast->next) {
                fast = fast->next->next;
                slow = slow->next;
                if(fast == slow) {
                    while(index != slow){
                        index = index->next;
                        slow = slow->next;
                    }
                    return index;
                }
            }
            return nullptr;
        }
    };