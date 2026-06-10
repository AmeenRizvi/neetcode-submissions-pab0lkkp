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

        while(t1 && t2)
        {
            int num = t1->val + t2->val + carry;
            // cout << num << " ";
            curr->next = new ListNode(num % 10);
            
            if(num / 10 != 0)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            curr = curr->next;
            t1 = t1->next;
            t2 = t2->next;
        }

        ListNode *t3 = t1 ? t1 : t2;
        while(t3)
        {
            int num = t3->val + carry;
            curr->next = new ListNode(num % 10);
            // cout << num << " ";
            
            if(num / 10 != 0)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            curr = curr->next;
            t3 = t3->next;
        }
        if(carry)
        {
            curr->next = new ListNode(carry);
            curr = curr->next;
        }

        ListNode *tempHead = dummy->next;
        dummy->next = NULL;
        delete dummy;

        ListNode *newHead = reverse(tempHead);
        return newHead;

        


    }
};