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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &preIdx, int l, int r)
    {
        if(l > r)
        {
            return NULL;
        }

        int subRoot = preorder[preIdx];
        int i = l;
        while(inorder[i] != subRoot)
        {
            i++;
        }
        preIdx++;

        TreeNode* node = new TreeNode(subRoot);
        node->left = helper(preorder, inorder, preIdx, l, i-1);
        node->right = helper(preorder, inorder, preIdx, i+1, r);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preIdx = 0;
        return helper(preorder, inorder, preIdx, 0, n-1);
        
    }
};
