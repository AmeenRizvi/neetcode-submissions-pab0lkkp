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
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* t1 = l1, *t2 = l2, *t3 = dummy;

        while(t1 && t2)
        {
            if(t1->val < t2->val)
            {
                t3->next = t1;
                t1 = t1->next;
            }
            else
            {
                t3->next = t2;
                t2 = t2->next;
            }
            t3 = t3->next;
        }

        if(t1) t3->next = t1;
        if(t2) t3->next = t2;

        return dummy->next;
    }

    ListNode* mergeSort(ListNode* head)
    {
        if(!head || !head->next)
        {
            return head;
        }

        ListNode* slow = head, *fast = head, *prev = NULL;

        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *t1 = head, *t2 = slow;
        prev->next = NULL;
        ListNode *T1 = mergeSort(t1);
        ListNode *T2 = mergeSort(t2);
        return merge(T1, T2);
    }

public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
        
    }
};
