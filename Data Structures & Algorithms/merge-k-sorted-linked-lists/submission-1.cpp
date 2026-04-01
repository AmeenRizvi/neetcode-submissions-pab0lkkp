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
        if(lists.empty())
            return NULL;

        auto cmp = [](ListNode* a, ListNode*b){return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype (cmp)> pq(cmp);

        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i] != NULL)
                pq.push(lists[i]);
        }

        ListNode* dummy = new ListNode(0);
        ListNode *tail = dummy;

        while(!pq.empty())
        {
            ListNode* top = pq.top();
            pq.pop();
            tail->next = new ListNode(top->val);
            tail = tail->next;

            if(top->next != NULL)
                pq.push(top->next);
        }
        return dummy->next;
    }
};
