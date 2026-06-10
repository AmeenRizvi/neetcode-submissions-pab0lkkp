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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *curr = head, *revPrev = NULL;
        for(int i = 1; i < left && curr != NULL; i++)
        {
            revPrev = curr;
            curr = curr->next;
        }

        ListNode *prev = NULL;
        ListNode *revFirst = curr, *nextNode = NULL;

        for(int i = left; i <= right && curr != NULL; i++)
        {
            ListNode *temp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = temp;
            if(i == right)
            {
                nextNode = curr;
            }
        }

        revFirst->next = nextNode;
        if(revPrev)
        {
            revPrev->next = prev;
        }

        return revPrev == NULL ? prev : head;

         

        
    }
};