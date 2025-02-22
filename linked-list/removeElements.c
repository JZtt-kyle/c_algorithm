/* 
 * 题目: 移除链表元素 
 * 功能描述: 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 
 * 网址:https://leetcode.cn/problems/remove-linked-list-elements/description/
*/

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head == NULL) return NULL; 
    struct ListNode* list = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* pre, *p;
    list->next = head;
    pre = list;
    p = head;
    while(p != NULL){
        if(p->val == val){
            struct ListNode* temp = p;
            pre->next = p->next;
            p = p->next;
            free(temp);
        }else{
            pre = p;
            p = p->next;
        }
    }
    head = list->next;
    free(list);
    return head;
}