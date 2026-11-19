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
    int dfs(TreeNode* node, int &ans)
    {
        if(node == NULL)
        {
            return 0;
        }

        int lst = dfs(node->left, ans);
        int leftVal = max(lst, 0);

        int rst = dfs(node->right, ans);
        int rightVal = max(rst, 0);

        ans = max(ans, leftVal + rightVal + node->val);

        return node->val + max(leftVal, rightVal);

    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = -1001;
        dfs(root, ans);

        return ans;

    }
};
