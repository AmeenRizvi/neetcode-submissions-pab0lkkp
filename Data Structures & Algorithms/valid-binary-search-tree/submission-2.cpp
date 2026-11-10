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
    bool dfs(TreeNode* node, int minVal, int maxVal)
    {
        if(node == NULL)
        {
            return true;
        }

        if(node->val <= minVal || node->val >= maxVal)
        {
            return false;
        }

        bool lst = dfs(node->left, minVal, node->val);
        bool rst = dfs(node->right, node->val, maxVal);

        return lst && rst;
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
        
    }
};
