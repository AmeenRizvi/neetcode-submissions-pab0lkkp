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
    bool helper(TreeNode* root, int c1, int c2)
    {
        if(root == NULL)
            return true;
        if(root->val <= c1 || root->val >= c2)
            return false;
        
        bool lst = helper(root->left, c1, root->val);
        bool rst = helper(root->right, root->val, c2);

        return lst && rst;
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, -INT_MAX, INT_MAX);
        
    }
};
