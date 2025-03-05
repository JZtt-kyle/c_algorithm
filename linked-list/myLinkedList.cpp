/* 
 * 题目: 设计链表 
 * 功能描述: 实现 MyLinkedList 类：
    MyLinkedList() 初始化 MyLinkedList 对象。
    int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
    void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
    void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
    void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
    void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
 * 网址:https://leetcode.cn/problems/design-linked-list/description/
*/

#include <iostream>
using namespace std;

class MyLinkedList {

    struct LinkedNode{
        int val;
        LinkedNode *next;
        LinkedNode(int val) : val(val), next(nullptr) {}
    };

    LinkedNode *head;
    int size;

    public:
        MyLinkedList() {
           head = new LinkedNode(0);
           size = 0;
        }
        
        int get(int index) {
           if(index >= size || index < 0) return -1;
           LinkedNode *cur = head->next;
           while(index--) {
                cur = cur->next;
           }
           return cur->val;
        }
        
        void addAtHead(int val) {
           LinkedNode *newNode = new LinkedNode(val);
           newNode->next = head->next;
           head->next = newNode;
           size++;
        }
        
        void addAtTail(int val) {
            LinkedNode *newNode = new LinkedNode(val);
            LinkedNode *cur = head;
            while(cur->next) {
                cur = cur->next;
            }
            cur->next = newNode;
            size++;
        }
        
        void addAtIndex(int index, int val) {
            if(index > size || index < 0) return;
            if(index == size) {
                addAtTail(val);
                return;
           }
           if(index == 0) {
                addAtHead(val);
                return;
           }
           LinkedNode *cur = head;
           LinkedNode *newNode = new LinkedNode(val);
           while(index--) {
                cur = cur->next;
           }
           newNode->next = cur->next;
           cur->next = newNode;
           size++;
        }
        
        void deleteAtIndex(int index) {
            if(index >= size || index <  0) return;
            LinkedNode *cur = head;
            while(index--) {
                cur = cur->next;
            }
            LinkedNode *tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
            size--;
        }
    };

