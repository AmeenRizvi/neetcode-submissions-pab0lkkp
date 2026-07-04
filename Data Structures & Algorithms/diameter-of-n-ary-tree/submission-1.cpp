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
    int findHeight(Node* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int h = 0;
        for(auto nbr : root->children)
        {
            h = max(h, findHeight(nbr));
        }
        return h+1;
    }
    int dfs(Node* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        vector<int>nodesHeight;
        for(auto nbr : root->children)
        {
            nodesHeight.push_back( findHeight(nbr) );
        }

        int largest = 0, secondLargest = 0;
        for(int h : nodesHeight)
        {
            if(h > largest)
            {
                secondLargest = largest;
                largest = h;
            }
            else if(h > secondLargest)
            {
                secondLargest = h;
            }
        }

        int op1 = largest + secondLargest;
        int op2 = 0;
        for(auto nbr : root->children)
        {
            op2 = max(op2,  dfs(nbr) );
        }

        return max(op1, op2);

    }
public:
    int diameter(Node* root) {
        return dfs(root);
        
    }
};
