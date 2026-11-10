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
    bool sameTree(TreeNode* node1, TreeNode* node2)
    {
        if(!node1 && !node2)
        {
            return true;
        }
        if(!node1 || !node2)
        {
            return false;
        }

        if(node1->val != node2->val)
        {
            return false;
        }

        bool lst = sameTree(node1->left, node2->left);
        bool rst = sameTree(node1->right, node2->right);

        return lst && rst;
    }
    bool dfs(TreeNode* node, TreeNode* subNode)
    {
        if(node == NULL)
        {
            return false;
        }

        if(node->val == subNode->val)
        {
            if(sameTree(node, subNode) )
            {
                return true;
            }
        }

        bool lst = dfs(node->left, subNode);
        bool rst = dfs(node->right, subNode);

        return lst || rst;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL)
        {
            return root == NULL;
        }
        return dfs(root, subRoot);
        
    }
};
