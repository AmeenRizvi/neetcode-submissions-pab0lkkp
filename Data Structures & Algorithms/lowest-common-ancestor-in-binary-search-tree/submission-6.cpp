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
    TreeNode* dfs(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if(!node || !p || !q)
        {
            return NULL;
        }

        TreeNode *lst = dfs(node->left, p, q);
        TreeNode *rst = dfs(node->right, p ,q);

        if( max(p->val, q->val) < node->val )
        {
            return lst;
        }
        else if(min(p->val, q->val) > node->val)
        {
            return rst;
        }
        return node;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(root == NULL) return NULL;
        // return p == NULL ? q : p;
        return dfs(root, p, q);
        
    }
};
