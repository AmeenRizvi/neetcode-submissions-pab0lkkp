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
    void dfs(TreeNode* root, unordered_map<int,int>&mp)
    {
        if(root == NULL)
        {
            return;
        }

        dfs(root->left, mp);
        mp[root->val]++;
        dfs(root->right, mp);
    }
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;

        dfs(root1, mp1);
        dfs(root2, mp2);
        
        for(auto &[num, freq] : mp1)
        {
            int diff = target - num;
            if(mp2.count(diff) )
            {
                return true;
            }
        }
        return false;
    }
};
