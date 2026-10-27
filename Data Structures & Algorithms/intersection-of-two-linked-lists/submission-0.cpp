/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* currA = headA, *currB = headB;
        int n = 0, m = 0;

        while(currA != NULL)
        {
            n++;
            currA = currA->next;
        }

        while(currB != NULL)
        {
            m++;
            currB = currB->next;
        }
        int skip = abs(n-m);
        currA = headA;
        currB = headB;
        
        for(int i = 0; i < skip; i++)
        {
            if(n < m)
            {
                currB = currB->next;
            }
            else
            {
                currA = currA->next;
            }
        }

        while(currA && currB)
        {
            if(currA == currB)
            {
                return currA;
            }
            currA = currA->next;
            currB = currB->next;
        }
        return NULL;
        
    }
};