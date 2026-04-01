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
    bool dfs(TreeNode*r1, TreeNode*r2, int target)
    {
        if(r1 == NULL) return NULL;

        int find = target - r1->val;
        TreeNode* tmp = r2;
        while(tmp != NULL)
        {
            if(tmp->val == find) return true;
            else if(tmp->val > find) tmp = tmp->left;
            else tmp = tmp->right;
        }

        bool left = dfs(r1->left, r2, target );
        bool right = dfs(r1->right, r2, target);

        return left || right;
    }
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        return dfs(root1, root2, target);
        
    }
};
