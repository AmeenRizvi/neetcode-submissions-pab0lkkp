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
    double maxAvg = 0;
    vector<int>dfs(TreeNode* root)
    {
        if(root == NULL)
        {
            return {0, 0};
        }

        vector<int>left = dfs(root->left);
        vector<int>right = dfs(root->right);

        int sum = left[0] + right[0] + root->val;
        int num = left[1] + right[1] + 1;
        maxAvg = max(maxAvg, (double)sum/num);
        return {sum, num}; 
    }
public:
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root);
        return maxAvg;
        
    }
};
