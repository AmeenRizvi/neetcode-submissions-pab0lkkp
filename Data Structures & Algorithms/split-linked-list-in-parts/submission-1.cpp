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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *curr = head;
        int N = 0;

        while(curr)
        {
            N++;
            curr = curr->next;
        }

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        curr = head;
        ListNode *prev = dummy;

        vector<ListNode*>ans;

        for(int i = 0; i < k; i++)
        {
            ListNode *t = curr;
            int sz = N/k + (i < N%k ? 1 : 0);

            for(int j = 0; j < sz; j++)
            {
                prev = t;
                t = t->next;
            }

            if(prev)
            {
                prev->next = NULL;
            }
            ans.push_back(curr);
            curr = t;
        }
        return ans;

        
    }
};
