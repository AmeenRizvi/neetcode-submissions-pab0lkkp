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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        unordered_map<int,int>mp;
        for(auto &num : nums)
        {
            mp[num]++;
        }

        ListNode *curr = head, *prev = dummy;

        while(curr)
        {
            if(mp.find(curr->val) != mp.end())
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
