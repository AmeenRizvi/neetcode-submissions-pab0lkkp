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
    pair<bool,int> dfs(TreeNode* root)
    {
        if(root == NULL)
        {
            return {true, 0};
        }

        pair<bool,int>lst = dfs(root->left);
        pair<bool,int>rst = dfs(root->right);

        int height = max(lst.second, rst.second) + 1;

        bool cond1 = abs(lst.second - rst.second) <= 1;
        bool cond2 = lst.first;
        bool cond3 = rst.first;

        return {cond1 && cond2 && cond3, height}; 
    }
public:
    bool isBalanced(TreeNode* root) {
        pair<bool,int>ans = dfs(root);
        return ans.first;
    }
};
