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
    bool sameTree(TreeNode* r1, TreeNode* r2)
    {
        if(r1 == NULL && r2 == NULL)
        {
            return true;
        }
        if(r1 == NULL || r2 == NULL)
        {
            return false;
        }
        bool lst = sameTree(r1->left, r2->left);
        bool rst = sameTree(r1->right, r2->right);

        return r1->val == r2->val && lst && rst;

    }
    bool dfs(TreeNode* r1, TreeNode* r2)
    {
        if(r1 == NULL && r2 == NULL)
        {
            return true;
        }
        if(r1 == NULL || r2 == NULL)
        {
            return false;
        }
        bool op1 = false;
        if(r1->val == r2->val)
        {
            op1 = sameTree(r1, r2);
        }

        bool lst = dfs(r1->left, r2);
        bool rst = dfs(r1->right, r2);

        return op1 || lst || rst;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
        
    }
};
