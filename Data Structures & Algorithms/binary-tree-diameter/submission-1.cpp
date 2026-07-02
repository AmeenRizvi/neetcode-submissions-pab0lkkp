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
    int height(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int lst = height(root->left);
        int rst = height(root->right);

        return max(lst, rst) + 1;
    }
    int dfs(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int lHeight = height(root->left);
        int rHeight = height(root->right);

        int currDiameter = lHeight + rHeight;

        int lDiameter = dfs(root->left);
        int rDiameter = dfs(root->right);

        return max({lDiameter, rDiameter, currDiameter});
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root);
        
    }
};
