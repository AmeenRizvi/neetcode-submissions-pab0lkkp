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
    int maxLength = 0;
    void dfs(TreeNode* p, TreeNode* parent, int length)
    {
        if(p == NULL)
        {
            return;
        }

        if(parent != NULL && p->val == parent->val + 1)
        {
            length++;
        }
        else
        {
            length = 1;
        }

        maxLength = max(maxLength, length);

        dfs(p->left, p, length);
        dfs(p->right, p, length);

    }
public:
    int longestConsecutive(TreeNode* root) {
        TreeNode* parent = NULL;
        dfs(root, parent, 0);
        return maxLength;
        
    }
};
