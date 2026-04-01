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
    int height(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int lst = height(root->left);
        int rst = height(root->right);

        return max(lst, rst)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int lsh = height(root->left);
        int rsh = height(root->right);

        if(abs(lsh - rsh) > 1)
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
