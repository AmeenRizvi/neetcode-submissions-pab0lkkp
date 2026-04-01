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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>store;
        ListNode* temp = NULL;
        for(int i = 0;  i < lists.size(); i++)
        {
            temp = lists[i];
            while(temp)
            {
                store.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(store.begin(), store.end());

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        for(int i = 0; i < store.size(); i++)
        {
            tail->next = new ListNode(store[i]);
            tail = tail->next;
        }
        return dummy->next;
        
    }
};
