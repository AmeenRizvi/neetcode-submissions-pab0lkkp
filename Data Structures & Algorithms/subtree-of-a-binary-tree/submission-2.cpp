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
    bool isSameTree(TreeNode* root, TreeNode* subRoot)
    {
        if(root == NULL && subRoot == NULL)
            return true;
        if(root != NULL && subRoot == NULL)
            return false;
        if(root == NULL && subRoot != NULL)
            return false;
        
        bool cond1 = root->val == subRoot->val;
        bool cond2 = isSameTree(root->left, subRoot->left);
        bool cond3 = isSameTree(root->right, subRoot->right);

        return cond1 && cond2 && cond3;

    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot)
            return true;
        if(!root)
            return false;
            
        if(isSameTree(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
        
        
    }
};
