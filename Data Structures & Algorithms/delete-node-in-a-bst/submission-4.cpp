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
    TreeNode* inorderSucc(TreeNode* node)
    {
        TreeNode *curr = node;
        curr = curr->right;
        while(curr->left != NULL)
        {
            curr = curr->left;
        }

        return curr;
    }
    TreeNode* deleteN(TreeNode* node)
    {
        if(node->left == NULL && node->right == NULL)
        {
            return NULL;
        }

        if(node->right == NULL)
        {
            return node->left;
        }

        TreeNode *succ = inorderSucc(node);
        node->val = succ->val;
        node->right = deleteNode(node->right, succ->val);
        return node;

    }
    TreeNode* dfs(TreeNode* node, int key)
    {
        if(node == NULL)
        {
            return NULL;
        }

        if(node->val == key)
        {
            return deleteN(node);
        }

        node->left = dfs(node->left, key);
        node->right = dfs(node->right, key);

        return node;

    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return dfs(root, key);
        
    }
};