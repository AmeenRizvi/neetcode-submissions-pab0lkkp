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
        vector<ListNode*>store;
        ListNode *temp = head;
        int sz = 0;

        while(temp)
        {
            sz++;
            store.push_back(temp);
            temp = temp->next;
        }

        int idx = sz-n;

        if(idx == 0)
            return head->next;
        
        store[idx-1]->next = store[idx]->next;
        return head;


        
    }
};
