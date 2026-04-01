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
    ListNode* reverseList(ListNode* head) {
        vector<int>store;
        ListNode* temp = head;
        while(temp != NULL)
        {
            store.push_back(temp->val);
            temp = temp->next;
        }

        reverse(store.begin(), store.end());
        temp = head;
        int i = 0;
        while(temp != NULL)
        {
            temp->val = store[i];
            i++;
            temp = temp->next;
        }

        return head;
        
    }
};
