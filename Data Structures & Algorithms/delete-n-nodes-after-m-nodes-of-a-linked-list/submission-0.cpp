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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode *curr = head;
        ListNode *lastNode = head;

        while(curr != NULL)
        {
            int mCount = m, nCount = n;

            while(curr != NULL && mCount != 0)
            {
                lastNode = curr;
                curr = curr->next;
                mCount--;
            }

            while(curr != NULL && nCount != 0)
            {
                curr = curr->next;
                nCount--;
            }

            lastNode->next = curr;
        }
        return head;
        
    }
};
