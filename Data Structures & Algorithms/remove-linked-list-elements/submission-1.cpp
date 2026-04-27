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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
        {
            return NULL;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *prev = dummy, *curr = head;

        while(curr != NULL)
        {
            ListNode* nxt = curr->next;
            if(curr->val == val)
            {
                prev->next = nxt;
            }
            else
            {
                prev = curr;
            }
            curr = nxt;
        }
        return dummy->next;


        
    }
};