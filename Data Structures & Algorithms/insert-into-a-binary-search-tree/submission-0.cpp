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
    TreeNode* dfs(TreeNode* root, int val)
    {
        if(root == NULL)
        {
            TreeNode* tmp = new TreeNode(val);
            return tmp;
        }

        if(root->val > val)
        {
            root->left = dfs(root->left, val);
        }
        else
        {
            root->right = dfs(root->right, val);
        }

        return root;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return dfs(root, val);
        
    }
};