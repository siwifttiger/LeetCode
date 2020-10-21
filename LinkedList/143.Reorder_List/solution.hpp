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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        //先找出链表中间节点
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //断链
        ListNode *last = slow->next;
        slow->next = NULL;
        
        //反转后半段链表
        ListNode *mid = last, *prev = NULL;
        while(mid)
        {
            last = mid->next;
            mid->next = prev;
            prev = mid;
            mid = last;
        }
        
        //将后半段链表插入前半链表
        while(prev && head)
        {
            ListNode *next = head->next;
            head->next = prev;
            prev = prev->next;
            head->next->next = next;
            head = next;
        }
    }
};