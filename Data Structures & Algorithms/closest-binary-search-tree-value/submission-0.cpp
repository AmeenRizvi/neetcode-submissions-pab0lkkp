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
    int closestValue(TreeNode* root, double target) {
        stack<TreeNode*>st;
        long long pred = LLONG_MIN;

        while(!st.empty() || root)
        {
            while(root)
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();

            if(pred <= target && target < root->val)
            {
                return abs(pred-target) <= abs(root->val - target) ? pred : root->val;
            }

            pred = root->val;
            root = root->right;
        }
        return pred;
        
    }
};
