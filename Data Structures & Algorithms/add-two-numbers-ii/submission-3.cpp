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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*>st1, st2;
        ListNode *t1 = l1, *t2 = l2;

        while(t1 != NULL)
        {
            st1.push(t1);
            t1 = t1->next;
        }

        while(t2 != NULL)
        {
            st2.push(t2);
            t2 = t2->next;
        }

        int carry = 0;
        ListNode *head = NULL;

        while(!st1.empty() || !st2.empty() || carry)
        {
            int num1 = !st1.empty() ? st1.top()->val : 0;
            if(!st1.empty()) st1.pop();

            int num2 = !st2.empty() ? st2.top()->val : 0;
            if(!st2.empty()) st2.pop();
            
            int num = num1 + num2 + carry;

            ListNode* node = new ListNode(num % 10);
            carry = num / 10;
            node->next = head;
            head = node;
        }
        return head;

        
    }
};