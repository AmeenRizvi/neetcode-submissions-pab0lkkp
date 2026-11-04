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
private:
    ListNode* reverse(ListNode *head)
    {
        ListNode *prev = NULL, *curr = head;

        while(curr)
        {
            ListNode *nxt = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nxt;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *rev1 = reverse(l1);
        ListNode *rev2 = reverse(l2);


        ListNode *dummy = new ListNode(-1);
        ListNode *t1 = rev1, *t2 = rev2, *t3 = dummy;
        int carry = 0;

        while(t1 || t2 || carry)
        {
            int sum = (t1 ? t1->val : 0) + (t2 ? t2->val : 0) + carry;
            int value = sum%10;
            carry = sum/10;

            t3->next = new ListNode(value);

            t1 = (t1 ? t1->next : NULL);
            t2 = (t2 ? t2->next : NULL);
            t3 = t3->next;
        }

        ListNode *rev3 = reverse(dummy->next);
        return rev3;
        
    }
};