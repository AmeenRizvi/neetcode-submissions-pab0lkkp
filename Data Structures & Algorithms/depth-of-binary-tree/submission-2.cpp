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
    int dfs(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int lst = dfs(root->left);
        int rst = dfs(root->right);

        return max(lst, rst) + 1;
    }
public:
    int maxDepth(TreeNode* root) {
        return dfs(root);
        
    }
};
