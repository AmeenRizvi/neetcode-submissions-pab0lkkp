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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int&rootIdx,
    int l, int r)
    {
        if(l > r)
            return NULL;
        int pivot = l;
        while(preorder[rootIdx] != inorder[pivot])
            pivot++;
        
        rootIdx++;
        TreeNode *newNode = new TreeNode(inorder[pivot]);
        newNode->left = build(preorder, inorder, rootIdx, l, pivot-1);
        newNode->right = build(preorder, inorder, rootIdx, pivot+1, r);

        return newNode;
    
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return build(preorder, inorder, rootIdx, 0, preorder.size()-1 );
        
    }
};
