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
    bool dfs(TreeNode* root)
    {
        if(root == NULL)
        {
            return true;
        }

        int lH = height(root->left);
        int rH = height(root->right);

        bool cond1 = abs(lH-rH) <= 1;

        bool cond2 = dfs(root->left);
        bool cond3 = dfs(root->right);

        return cond1 && cond2 && cond3;
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root);
        
    }
};
