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
    int dfs(TreeNode* node)
    {
        if(node == NULL) return 0;

        int lh = dfs(node->left);
        int rh = dfs(node->right);

        return max(lh, rh) + 1;
    }
public:
    int maxDepth(TreeNode* root) {
        return dfs(root);
        
    }
};
