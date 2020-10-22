/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /* 递归 */
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *next = head;
        while(cur != nullptr)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

/* 迭代
核心思想是加一个虚拟头，另外有3个指针
pre cur next
每次循环让 cur->next 指向 pre 
同时同步向后移动这3个指针，这样遍历完链表就逆转完了
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *next = cur;
        while(cur != NULL)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
            
    }
};