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
        if(!head) return false;
        
        ListNode *fast = head->next, *slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            if(fast == slow) return true;

            fast = fast->next->next;
            slow = slow->next;
        }

        return false;
        
    }
};
