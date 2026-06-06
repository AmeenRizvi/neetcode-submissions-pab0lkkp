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
    ListNode*  findMiddle(ListNode* head)
    {
    	ListNode *slow = head, *fast = head;
    	while(fast != NULL && fast->next != NULL)
    	{
    		fast = fast->next->next;
    		slow = slow->next;
        }
        return slow;	
    }
ListNode* reverse(ListNode *l2)
{
	ListNode* prev = NULL, *curr = l2;
	
	while(curr != NULL)
	{
		ListNode *temp = curr->next;
		
		curr->next = prev;
		prev = curr;
		curr = temp;
    }
    return prev;
}

void merge(ListNode *l1, ListNode *l2)
{
	ListNode *dummy = new ListNode(0);
	ListNode * curr = dummy;
	ListNode *t1 = l1, *t2 = l2;

	bool flag = true;
	while(t1 != NULL && t2 != NULL)
	{
		if(flag)
		{
			curr->next = t1;
			t1 = t1->next;
        }
        else
        {
    	    curr->next = t2;
    	    t2 = t2->next;
        }
        curr = curr->next;
        flag = !flag;
    }
    curr->next = t1 ? t1 : t2;
    
}

public:
    void reorderList(ListNode* head) {
        ListNode* middle = findMiddle(head);
    	ListNode *l1 = head, *l2 = middle->next;
        middle->next = NULL;

        l2 = reverse(l2);

        merge(l1, l2);
        
    }
};
