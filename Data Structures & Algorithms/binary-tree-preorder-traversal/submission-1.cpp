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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode* cur = root;

        while(cur || !st.empty())
        {
            if(cur)
            {
                ans.push_back(cur->val);
                st.push(cur->right);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
            }
        }
        return ans;
    }
};