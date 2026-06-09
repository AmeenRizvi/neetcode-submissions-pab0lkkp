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
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL) return true; 

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *slow = dummy, *fast = dummy;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *l2 = slow->next;
        ListNode *l1 = dummy->next;

        dummy->next = NULL;
        delete dummy;

        ListNode *newL2 = reverse(l2);

        ListNode *t1 = l1, *t2 = newL2;

        while(t1 && t2)
        {
            cout << t1->val << " " << t2->val;
            if(t1->val != t2->val)
            {
                return false;
            }

            t1 = t1->next;
            t2 = t2->next;
        }
        return true;        
    }
};