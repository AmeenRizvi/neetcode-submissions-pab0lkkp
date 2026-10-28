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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *curr1 = list1, *curr2 = list2;
        ListNode *t1 = list1, *t2 = list1;

        for(int i = 0; i < a-1; i++)
        {
            t1 = t1->next;
        }

        for(int i = 0; i < b; i++)
        {
            t2 = t2->next;
        }

        t1->next = curr2;
        while(curr2->next)
        {
            curr2 = curr2->next;
        }

        curr2->next = t2->next;
        t2->next = NULL;
        return list1;
        
    }
};
