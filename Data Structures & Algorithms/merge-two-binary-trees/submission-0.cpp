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
    TreeNode* dfs(TreeNode* r1, TreeNode* r2)
    {
        if(r1 == NULL && r2 == NULL)
        {
            return NULL;
        }

        int sum = 0;
        sum += r1 == NULL ? 0 : r1->val;
        sum += r2 == NULL ? 0 : r2->val;

        TreeNode *root = new TreeNode(sum);
        root->left = dfs(r1 ? r1->left : NULL, r2 ? r2->left : NULL);
        root->right = dfs(r1 ? r1->right : NULL, r2 ? r2->right : NULL);

        return root;

    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);

    }
};