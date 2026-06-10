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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *rev1 = reverse(l1);
        ListNode *rev2 = reverse(l2);

        ListNode *dummy = new ListNode(-1);
        ListNode *t1 = rev1, *t2 = rev2, *curr = dummy;
        int carry = 0;

        while(t1 || t2 || carry)
        {
            int num1 = t1 ? t1->val : 0;
            int num2 = t2 ? t2->val : 0;
            int num = num1 + num2 + carry;

            curr->next = new ListNode(num % 10);
            
            carry = num / 10 ;
            
            curr = curr->next;
            t1 ? t1 = t1->next : NULL;
            t2 ? t2 = t2->next : NULL;
        }

        ListNode *tempHead = dummy->next;
        dummy->next = NULL;
        delete dummy;

        ListNode *newHead = reverse(tempHead);
        return newHead;

    }
};