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
    ListNode* swapPairs(ListNode* head) {
        int n = 0;
        ListNode *curr = head;
        while(curr)
        {
            n++;
            curr = curr->next;
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy;
        curr = head;

        for(int i = 0; i < n && curr ; i=i+2)
        {
            ListNode *t1 = curr;
            ListNode *t2 = curr->next;
            ListNode *nxt = NULL;
            if(t2)
            {
                nxt = t2->next;

                t2->next = t1;
                prev->next = t2;
            }
            t1->next = nxt;

            prev = prev->next->next;
            curr = nxt;
        }
        return dummy->next;
        
    }
};
