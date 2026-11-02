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
    ListNode* sortLinkedList(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *back = head;
        if(!head || !head->next)
        {
            return head;
        }

        while(curr)
        {
            if(curr->val < 0)
            {
                if(!prev)
                {
                    prev = curr;
                    curr = curr->next;
                }
                else
                {
                    prev->next = curr->next;
                    curr->next = back;
                    back = curr;
                    curr = prev->next;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return back;

    }
};
