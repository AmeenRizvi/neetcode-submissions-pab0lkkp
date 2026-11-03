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
    int pairSum(ListNode* head) {
        ListNode *curr = head;
        unordered_map<int,int>mp;
        int n = 0, maxSum = 0;
        while(curr)
        {
            n++;
            curr = curr->next;
        }
        curr = head;
        for(int i = 0; i < n; i++)
        {
            if(i <= (n/2)-1)
            {
                mp[i] = curr->val;
            }
            else
            {
                int sum = curr->val + mp[n-1-i];
                maxSum = max(maxSum, sum);
            }
            curr = curr->next;
        }
        return maxSum;
    }
};