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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        if(root == NULL)
        {
            return ans;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight = true;

        while(!q.empty())
        {
            int sz = q.size();
            vector<int>level(sz, 0);
            for(int i = 0; i < sz; i++)
            {
                TreeNode* front = q.front();
                q.pop();
                // level.push_back(front->val);
                
                if(front->left)
                {
                    q.push(front->left);
                }
                if(front->right)
                {
                    q.push(front->right);
                }

                if(leftToRight)
                {
                    level[i] = front->val;
                }
                else
                {
                    level[sz-i-1] = front->val;
                }
            }
            ans.push_back(level);
            leftToRight = !leftToRight;
        }
        return ans;

        
    }
};