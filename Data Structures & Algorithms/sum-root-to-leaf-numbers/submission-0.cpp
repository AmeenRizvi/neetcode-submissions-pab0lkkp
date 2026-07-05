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
    vector<vector<int>>numsArray;

    void dfs(TreeNode* root, vector<int>&path)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->left == NULL && root->right == NULL)
        {
            path.push_back(root->val);
            numsArray.push_back(path);
            path.pop_back();
            return;
        }

        path.push_back(root->val);
        dfs(root->left, path);
        dfs(root->right, path);

        path.pop_back();
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<int>path;
        dfs(root, path);

        int sum = 0;

        for(auto arr : numsArray)
        {
            int number = 0;
            for(int digit : arr)
            {
                cout << digit << " ";
                number = number*10 + digit;

            }
            sum += number;
        }
        return sum;
    }
};