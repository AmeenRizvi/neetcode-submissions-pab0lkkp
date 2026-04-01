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
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, ListNode*>mp;
        ListNode* temp = head;

        while(temp != NULL)
        {
            if(mp.find(temp) != mp.end())
                return true;

            mp[temp] = temp->next;
            temp = temp->next;
        }
        return false;
        
    }
};
