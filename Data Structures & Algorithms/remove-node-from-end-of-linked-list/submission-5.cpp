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
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *prev = dummy, *curr = head, *curr2 = head;

        for(int i = 0; i < n; i++)
        {
            curr2 = curr2->next;
        }

        while(curr2)
        {
            prev = curr;
            curr = curr->next;
            curr2 = curr2->next;
        }
        
        prev->next = curr->next;
        delete curr;

        ListNode *ans = dummy->next;
        delete dummy;
        return ans;

        
    }
};
