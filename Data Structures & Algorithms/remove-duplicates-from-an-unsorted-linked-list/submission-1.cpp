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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy,*curr = head;

        unordered_map<int,int>freq;

        while(curr)
        {
            freq[curr->val]++;
            curr = curr->next;
        }

        curr = head;

        while(curr)
        {
            if(freq[curr->val] > 1)
            {
                prev->next = curr->next;
            }
            else
            {
                prev = curr;
            }
            curr = curr->next;
        }

        return dummy->next;
    }
};
