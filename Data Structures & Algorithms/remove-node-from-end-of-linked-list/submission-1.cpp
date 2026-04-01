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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *temp = head;
        int sz = 0;

        while(temp)
        {
            sz++;
            temp = temp->next;
        }

        int idx = sz-n;

        if(idx == 0)
            return head->next;
        
        temp = head;
        for(int i = 0; i < sz-1; i++)
        {
            if((i+1) == idx)
            {
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }

        return head;


        
    }
};
