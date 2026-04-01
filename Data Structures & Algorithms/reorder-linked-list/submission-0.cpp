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
        vector<int>store;
        ListNode *temp = head;
        while(temp)
        {
            store.push_back(temp->val);
            temp = temp->next;
        }

        int l = 0, r = store.size()-1;
        temp = head;
        
        while(l < r)
        {
            temp->val = store[l++];
            temp = temp->next;

            temp->val = store[r--];
            temp = temp->next;
        }

        if(store.size() % 2 == 1)
        {
            temp->val = store[l++];
            temp = temp->next;
        }

        
    }
};
