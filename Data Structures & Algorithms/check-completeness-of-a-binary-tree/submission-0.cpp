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
    int countNodes(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    bool dfs(TreeNode* root, int n, int index)
    {
        if(root == NULL)
        {
            return true;
        }
        if(index >= n)
        {
            return false;
        }

        return dfs(root->left, n, 2*index+1) && dfs(root->right, n, 2*index+2);
    }
public:
    bool isCompleteTree(TreeNode* root) {
        int n = countNodes(root);
        return dfs(root, n, 0);
        
    }
};