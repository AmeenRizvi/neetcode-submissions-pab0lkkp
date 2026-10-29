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
private:
    ListNode* reverse(ListNode *head)
    {
        ListNode *prev = NULL, *curr = head;

        while(curr != NULL)
        {
            ListNode *next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* plusOne(ListNode* head) {

        ListNode* h1 = reverse(head);

        ListNode *curr = h1;
        curr->val += 1;
        int carry = 0;

        while(curr != NULL)
        {
            int value = (curr->val + carry)%10;
            carry = (curr->val + carry)/10;
            
            curr->val = value;
            if(curr->next == NULL && carry == 1)
            {
                curr->next = new ListNode(carry);
                carry = 0;
            }
            curr = curr->next;
        }
        
        ListNode* h2 = reverse(h1);
        return h2;  
        
    }
};
