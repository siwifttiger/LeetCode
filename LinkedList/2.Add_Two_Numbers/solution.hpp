/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val = 0;
        int carry = 0;
        int sum = 0;
        auto dummy = new ListNode(0);
        auto first = dummy;
        while(l1 || l2)
        {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            dummy->next = new ListNode(sum % 10);
            carry = ((sum - 10 >= 0 )? 1 : 0);
            dummy = dummy->next;
            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }
        }
        if (carry == 1)
        {
            dummy->next = new ListNode(1);
        }
        return first->next;
    }
};