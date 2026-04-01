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
    int count = 0;
    bool dfs(TreeNode* root)
    {
        if(root == NULL)
        {
            return true;
        }

        bool left = dfs(root->left);
        bool right = dfs(root->right);

        if(left && right)
        {
            if(root->left != NULL && root->left->val != root->val)
            {
                return false;
            }
            if(root->right != NULL && root->right->val != root->val)
            {
                return false;
            }
            count++;
            return true;
        }
        return false;


    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        dfs(root);
        return count;
        
    }
};
