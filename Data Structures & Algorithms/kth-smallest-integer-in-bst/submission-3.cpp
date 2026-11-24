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
    void dfs(TreeNode* node, vector<int>&temp)
    {
        if(node == NULL)
        {
            return;
        }

        dfs(node->left, temp);
        temp.push_back(node->val);
        dfs(node->right, temp);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>temp;
        if(root == NULL)
        {
            return -1;
        }
        dfs(root, temp);

        return temp[k-1];
        
    }
};
