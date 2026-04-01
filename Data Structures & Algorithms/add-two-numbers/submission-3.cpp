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
        while(tail1 || tail2 || carry != 0)
        {
            int v1 = (tail1 != NULL) ? tail1->val : 0;
            int v2 = (tail2 != NULL) ? tail2->val : 0;

            int value = v1 + v2 + carry;
            carry = value/10;
            value = value%10;

            tail3->next = new ListNode(value);

            tail1  = tail1 != NULL ? tail1->next : NULL;
            tail2  = tail2 != NULL ? tail2->next : NULL ;
            tail3  = tail3->next;
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
        
    }
};
