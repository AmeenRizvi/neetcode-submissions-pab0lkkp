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
    ListNode* removeNodes(ListNode* head) {
        // montonic stack
        stack<ListNode*>st;
        ListNode *curr = head;

        while(curr)
        {
            while(!st.empty() && curr->val > st.top()->val)
            {
                st.pop();
            }
            st.push(curr);
            curr = curr->next;
        }

        ListNode *dummy = new ListNode(0);
        curr = dummy;

        while(!st.empty())
        {
            ListNode *top = st.top();
            st.pop();

            curr->next = top;
            curr = curr->next;
        }
        curr->next = NULL;

        ListNode *h1 = dummy->next;
        dummy->next = NULL;

        // reverse LL
        ListNode *prev = NULL;
        curr = h1;

        while(curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;

        
    }
};
