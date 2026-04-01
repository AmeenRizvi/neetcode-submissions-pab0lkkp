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
        ListNode *tail1 = l1, *tail2 = l2;
        ListNode *dummy = new ListNode(-1);
        ListNode *tail3 = dummy;

        int carry = 0;
        while(tail1 && tail2)
        {
            int value = tail1->val + tail2->val + carry;
            carry = value/10;
            value = value%10;

            tail3->next = new ListNode(value);

            tail1  = tail1->next;
            tail2  = tail2->next;
            tail3  = tail3->next;
        }

        while(tail1)
        {
            int value = tail1->val + carry;
            carry = value/10;
            value = value%10;

            tail3->next = new ListNode(value);

            tail1 = tail1->next;
            tail3 = tail3->next;
        } 

        while(tail2)
        {
            int value = tail2->val + carry;
            carry = value/10;
            value = value%10;

            tail3->next = new ListNode(value);

            tail2 = tail2->next;
            tail3 = tail3->next;
        }

        if(carry)
        {
            tail3->next = new ListNode(carry);
        } 

        return dummy->next;
        
    }
};
