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
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode *prev = NULL;
        TreeNode *prevRight = NULL;

        while(curr != NULL)
        {
            TreeNode* next = curr->left;
            TreeNode* right = curr->right;

            curr->left = prevRight;
            curr->right = prev;

            prev = curr;
            prevRight = right;
            curr = next;
        }
        return prev;
        
    }
};
