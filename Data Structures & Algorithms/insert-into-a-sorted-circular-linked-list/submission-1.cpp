class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head == NULL)
        {
            Node *temp = new Node(insertVal);
            temp->next = temp;
            return temp;
        }
        if(head->next == head)
        {
            Node *temp = new Node(insertVal);
            head->next = temp;
            temp->next = head;
            return head;
        }

        Node *prev = head, *curr = head->next;
        while(1)
        {
            if(prev->val <= insertVal && insertVal <= curr->val)
            {
                Node *temp = new Node(insertVal);
                prev->next = temp;
                temp->next = curr;
                return head;
            }
            if(prev->val > curr->val)
            {
                if(insertVal >= prev->val || insertVal <= curr->val)
                {
                    Node *temp = new Node(insertVal);
                    prev->next = temp;
                    temp->next = curr;
                    return head;
                }
            }
            prev = curr;
            curr = curr->next;
            if(prev == head) break;
        }
        Node *temp = new Node(insertVal);
        prev->next = temp;
        temp->next = curr;
        return head;
    }
};