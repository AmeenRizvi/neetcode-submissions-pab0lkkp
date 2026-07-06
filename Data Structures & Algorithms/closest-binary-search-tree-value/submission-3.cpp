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
    double minDiff;
    void dfs(TreeNode* root, double target, int &ans)
    {
        if(root == NULL)
        {
            return;
        }

        double diff = abs(root->val - target);
        if(diff < minDiff)
        {
            minDiff = diff;
            ans = root->val;
        }
        dfs(root->left, target, ans);
        dfs(root->right, target, ans);

    }
public:
    int closestValue(TreeNode* root, double target) {
        int ans = -1;
        minDiff = 1e9;
        dfs(root, target, ans);
        return ans == 1e9 ? -1 : ans;
        
    }
};
