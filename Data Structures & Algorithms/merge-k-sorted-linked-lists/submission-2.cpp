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
    struct cmp{
        bool operator()(ListNode*a, ListNode*b){
            return a->val > b->val;
        }

    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        ListNode *dummy = new ListNode(-10001);
        ListNode *t = dummy;

        int n = lists.size();

        for(int i = 0; i < n; i++)
        {
            if(lists[i])
            {
                pq.push(lists[i]);
            }
        }

        while(!pq.empty() )
        {
            ListNode *minNode = pq.top();
            pq.pop();

            t->next = minNode;
            t = t->next;

            minNode = minNode->next;
            if(minNode)
            {
                pq.push(minNode);
            }
        }

        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};
