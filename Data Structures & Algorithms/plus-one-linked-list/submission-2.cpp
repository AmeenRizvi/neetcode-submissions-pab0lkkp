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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL, *curr = head;
        while(curr != NULL)
        {
            ListNode *temp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = temp;
        }
        return prev;
    }

public:
    ListNode* plusOne(ListNode* head) {
        ListNode* newHead = reverse(head);

        int carry = 1;
        ListNode *curr = newHead;
        while(curr != NULL)
        {        
            int num = curr->val;
            curr->val = (curr->val + carry)%10;

            if( (num + carry)/10 == 1 )
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            
            
            if(curr->next == NULL && carry == 1)
            {
                curr->next = new ListNode(carry);
                carry = 0;
            }
            curr = curr->next;
        }

        ListNode* ansHead = reverse(newHead);
        return ansHead;
    }
};
