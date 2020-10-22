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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        auto slow = head;
        auto fast = head;
        while(slow && fast)
        {
            slow = slow->next;
            if (!fast->next)
            {
                return nullptr;
            }
            fast = fast->next->next;
            if (slow == fast)
            {
                auto ptr = head;
                while(slow != ptr)
                {
                    slow = slow->next;
                    ptr = ptr->next;
                }
                return slow;
            }
        }

        return nullptr;
    }
};