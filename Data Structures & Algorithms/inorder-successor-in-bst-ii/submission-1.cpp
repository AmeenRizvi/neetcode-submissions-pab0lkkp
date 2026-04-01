/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        Node* tmp = node;

        if(tmp->right)
        {
            tmp = tmp->right;
            while(tmp->left != NULL)
            {
                tmp = tmp->left;
            }
            return tmp;
        }
        
        while(tmp->parent && tmp == tmp->parent->right)
        {
            tmp = tmp->parent;
        }
    
        return tmp->parent;
        
    }
};
