/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    bool isLeaf(TreeNode* root)
    {
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL)
        {
            return true;
        }

        return false;
    }

    void addLeaves(TreeNode* root, vector<int>&ans)
    {
        if(root == NULL)
        {
            return;
        }

        if(isLeaf(root))
        {
            ans.push_back(root->val);
        }

        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root == NULL) return {};
        vector<int>ans;

        if(!isLeaf(root))
        {
            ans.push_back(root->val);
        }

        TreeNode *t = root->left;

        while(t != NULL)
        {
            if(!isLeaf(t))
            {
                ans.push_back(t->val);
            }
            if(t->left != NULL)
            {
                t = t->left;
            }
            else
            {
                t = t->right;
            }
        }

        addLeaves(root, ans);

        stack<int>st;
        t = root->right;
        while(t != NULL)
        {
            if(!isLeaf(t))
            {
                st.push(t->val);
            }
            if(t->right != NULL)
            {
                t = t->right;
            }
            else
            {
                t = t->left;
            }
        }

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;        
    }
};
