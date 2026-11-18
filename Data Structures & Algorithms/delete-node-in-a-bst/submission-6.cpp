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
private:
    TreeNode* bstSearch(TreeNode *node, int key)
    {
        if(node == NULL)
        {
            return NULL;
        }

        if(node->val < key)
        {
            node->right = bstSearch(node->right, key);
        }
        else if(node->val > key)
        {
            node->left = bstSearch(node->left, key);
        }
        else
        {
            if(node->left == NULL)
            {
                return node->right;
            }
            else if(node->right == NULL)
            {
                return node->left;
            }

            TreeNode *curr = node->right;
            while(curr->left)
            {
                curr = curr->left;
            }

            node->val = curr->val;
            node->right = deleteNode(node->right, curr->val);
            return node;
        }
        return node;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return bstSearch(root, key);
        
    }
};