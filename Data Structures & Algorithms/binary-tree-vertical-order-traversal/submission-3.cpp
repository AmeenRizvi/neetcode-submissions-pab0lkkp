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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == NULL)
        {
            return {};
        }
        queue< pair< TreeNode*, int>>q;
        map<int, vector<int>>mp;
        q.push({root, 0});
        mp[0].push_back(root->val);

        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                TreeNode* node = q.front().first;
                int colNo = q.front().second;
                q.pop();

                if(node->left)
                {
                    q.push({node->left, colNo-1});
                    mp[colNo-1].push_back(node->left->val);
                }
                if(node->right)
                {
                    q.push({node->right, colNo+1});
                    mp[colNo+1].push_back(node->right->val);
                }
            }
        }

        vector<vector<int>>ans;
        for(auto &[colNo, nodesVect] : mp )
        {
            ans.push_back(nodesVect);
        }
        return ans;
    }
};