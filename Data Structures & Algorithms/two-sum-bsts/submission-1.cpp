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
    void dfs(TreeNode* root, vector<int>&nums)
    {
        if(root == NULL) return;

        dfs(root->left, nums);
        nums.push_back(root->val);
        dfs(root->right, nums);
    }
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int>nums1;
        vector<int>nums2;

        dfs(root1, nums1);
        dfs(root2, nums2);

        int p1 = 0, p2 = nums2.size()-1;

        while(p1 < nums1.size() && p2 >= 0 )
        {
            if(nums1[p1] + nums2[p2] == target)
            {
                return true;
            }
            else if(nums1[p1] + nums2[p2] < target )
            {
                p1++;
            }
            else
            {
                p2--;
            }
        }
        return false;
        
    }
};
