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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue< pair<TreeNode*, TreeNode*>>que;
        que.push({p, q});

        while(!que.empty())
        {
            int sz = que.size();
            for(int i = 0; i < sz; i++)
            {
                TreeNode* r1 = que.front().first;
            TreeNode* r2 = que.front().second;
            que.pop();

            if(!r1 && !r2)
                continue;
            if(!r1 || !r2 || r1->val != r2->val)
                return false;
            
            que.push({r1->left, r2->left});
            que.push({r1->right, r2->right});
            }
        }
        return true;
        
    }
};
