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
    bool dfs(TreeNode* root, int &sum, int targetSum)
    {
        if(root == NULL)
        {
            return false;
        }

        sum += root->val;
        if(root->left == NULL && root->right == NULL)
        {
            bool ans = sum == targetSum;
            sum -= root->val;
            return ans;
        }

        bool lst = dfs(root->left, sum, targetSum);
        bool rst = dfs(root->right, sum, targetSum);

        sum -= root->val;
        return lst || rst;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return dfs(root, sum, targetSum);
        
    }
};