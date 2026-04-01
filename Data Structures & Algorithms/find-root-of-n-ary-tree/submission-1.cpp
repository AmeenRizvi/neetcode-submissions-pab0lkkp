/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        int valueSum = 0;

        for(Node* node : tree)
        {
            valueSum += node->val;
            for(Node *child : node->children)
            {
                valueSum -= child->val;
            }
        }

        Node *root = NULL;

        for(Node* node : tree)
        {
            if(node->val == valueSum)
            {
                root = node;
            }
        }
        return root;
    }
};
