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
        TreeNode* tmp = root->right;
        while(tmp->left != NULL)
        {
            tmp = tmp->left;
        }
        return tmp;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;

        if(root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if(root->left == NULL)
            {
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }
            else if(root->right == NULL)
            {
                TreeNode *tmp = root->left;
                delete root;
                return tmp;
            }
            
            TreeNode *succ = inorderSucc(root);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
            
        }
        return root;
        
    }
};