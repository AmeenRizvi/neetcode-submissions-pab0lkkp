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
    bool search(int num, TreeNode* root)
    {
        while(root != NULL)
        {
            if(root->val == num)
            {
                return true;
            }
            else if(root->val > num)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return false;

    }
    bool dfs(TreeNode* root1, TreeNode* root2, int target)
    {
        if(root1 == NULL)
        {
            return false;
        }
        if( search(target - root1->val, root2) )
        {
            return true;
        }
        bool left = dfs(root1->left, root2, target);
        bool right = dfs(root1->right, root2, target);

        return left || right;
    }
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        return dfs(root1, root2, target);
        
    }
};
