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
        unordered_set<int>s;

        for(Node* node : tree)
        {
            for(Node *child : node->children)
            {
                s.insert(child->val);
            }
        }

        Node *root = NULL;

        for(Node* node : tree)
        {
            if(s.find(node->val) == s.end())
            {
                root = node;
            }
        }
        return root;
    }
};
