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
    void dfs(TreeNode* node, vector<int>&store)
    {
        if(node == NULL)
        {
            return;
        }

        dfs(node->left, store);
        store.push_back(node->val);
        dfs(node->right, store);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>store;
        dfs(root, store);

        return store[k-1];
        
    }
};
