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
    int getHeight(TreeNode* root)
    {
        if(root == NULL)
        {
            return -1;
        }

        int left = getHeight(root->left);
        int right = getHeight(root->right);

        return max(left, right) + 1;
    }
    void dfs(TreeNode* root, map<int, vector<int>>&mp)
    {
        if(root == NULL)
        {
            return;
        }

        int height = getHeight(root);
        mp[height].push_back(root->val);

        dfs(root->left, mp);
        dfs(root->right, mp);
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        map<int, vector<int>>mp;
        dfs(root, mp);

        vector<vector<int>>ans;
        for(auto &p : mp)
        {
            ans.push_back(p.second);
        }
        return ans;
        
    }
};
