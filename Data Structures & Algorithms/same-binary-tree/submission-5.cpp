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
    bool dfs(TreeNode* nodeP, TreeNode* nodeQ)
    {
        if(nodeP == NULL && nodeQ == NULL)
        {
            return true;
        }

        if(nodeP == NULL || nodeQ == NULL)
        {
            return false;
        }

        if(nodeP->val != nodeQ->val)
        {
            return false;
        }

        bool left = dfs(nodeP->left, nodeQ->left);
        bool right = dfs(nodeP->right, nodeQ->right);

        return left && right;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
        
    }
};
