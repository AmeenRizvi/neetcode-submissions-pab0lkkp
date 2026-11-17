/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* dfs(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if(node == NULL)
        {
            return NULL;
        }

        if(node == p || node == q)
        {
            return node;
        }
        TreeNode *lst = dfs(node->left, p, q);
        TreeNode *rst = dfs(node->right, p, q);

        if(lst && rst)
        {
            return node;
        }

        return lst ? lst : rst;

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
        
    }
};