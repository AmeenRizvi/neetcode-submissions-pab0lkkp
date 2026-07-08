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
    TreeNode* inorderSucc(TreeNode* root)
    {
        TreeNode* curr = root;
        curr = root->right;
        while(curr->left != NULL )
        {
            curr = curr->left;
        }
        return curr;
    }
    TreeNode* removeNode(TreeNode* root)
    {
        if(root->left == NULL && root->right == NULL)
        {
            return NULL;
        }

        if(root->right == NULL)
        {
            return root->left;
        }

        TreeNode* temp = inorderSucc(root);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
        return root;

    }
    TreeNode* dfs(TreeNode* root, int key)
    {
        if(root == NULL)
        {
            return NULL;
        }

        if(root->val == key)
        {
            return removeNode(root);
        }

        root->left = dfs(root->left, key);
        root->right = dfs(root->right, key);

        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return dfs(root, key);
        
    }
};