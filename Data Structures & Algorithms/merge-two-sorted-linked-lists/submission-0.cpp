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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int>store;
        ListNode* temp = list1;
        while(temp)
        {
            store.push_back(temp->val);
            temp = temp->next;
        }
        temp = list2;
        while(temp)
        {
            store.push_back(temp->val);
            temp = temp->next;
        }

        sort(store.begin(), store.end());
        ListNode *dummy = new ListNode(0);
        temp = dummy;

        for(int i = 0; i < store.size(); i++)
        {
            temp->next = new ListNode(store[i]);
            temp = temp->next;
        }

        return dummy->next;




    }
};
