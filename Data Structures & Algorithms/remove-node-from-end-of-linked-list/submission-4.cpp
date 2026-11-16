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
        ListNode *l1 = head, *l2 = head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy;

        for(int i = 0; i < n; i++)
        {
            l1 = l1->next;
        }

        while(l1)
        {
            prev = l2;
            l2 = l2->next;
            l1 = l1->next;
        }

        prev->next = l2->next;
        delete l2;

        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
        
    }
};
