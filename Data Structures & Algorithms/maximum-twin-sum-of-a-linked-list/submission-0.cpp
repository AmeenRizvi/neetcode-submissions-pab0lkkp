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
    ListNode* reverse(ListNode *head)
    {
        ListNode *prev = NULL, *curr = head;

        while(curr != NULL)
        {
            ListNode *temp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = temp;
        }
        return prev;
    }
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }


        ListNode *l1 = head;
        ListNode *l2 = reverse(slow);
        int maxSum = 0;

        while(l1 && l2)
        {
            int sum = l1->val + l2->val;
            maxSum = max(maxSum, sum);
            l1 = l1->next;
            l2 = l2->next;
        }
        return maxSum;
    }
};