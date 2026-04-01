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
    void reorderList(ListNode* head) {

        ListNode *s = head , *f = head;
        
        while(f && f->next)
        {
            f = f->next->next;
            s = s->next;
        }

        ListNode *h1 = head, *h2 = s->next, *prev = NULL;
        s->next = NULL;

        ListNode* curr = h2;
        while(curr)
        {
            ListNode *t = curr->next;
            curr->next = prev;
            prev = curr;
            curr = t;
        }
        h2 = prev;

        while(h2)
        {
            ListNode *temp1 = h1->next;
            ListNode* temp2 = h2->next;

            h1->next = h2;
            h2->next = temp1;

            h1 = temp1;
            h2 = temp2;
        }

    }
};
