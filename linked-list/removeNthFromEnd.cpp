/* 
 * 题目: 两两交换链表中的节点
 * 功能描述: 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点
 * 网址:https://leetcode.cn/problems/swap-nodes-in-pairs/description/
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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *slow = head;
            ListNode *fast = head;
            for(int i = 0; i < n; i++) fast = fast->next;
            if(!fast){
                return head->next;
            }
            while(fast->next){
                slow = slow->next;
                fast = fast->next;
            }
            ListNode *tmp = slow->next;
            slow->next = tmp->next;
            delete tmp;
            return head;
        }
    };