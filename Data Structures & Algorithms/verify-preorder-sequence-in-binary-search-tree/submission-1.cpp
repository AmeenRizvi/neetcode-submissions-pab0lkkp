class Solution {
    bool dfs(vector<int>& preorder, int &i, int minLimit, int maxLimit)
    {
        if(i == preorder.size())
        {
            return true;
        }

        int root = preorder[i];
        if(root <= minLimit || root >= maxLimit)
        {
            return false;
        }

        i++;
        bool left = dfs(preorder, i, minLimit, root);
        bool right = dfs(preorder, i, root, maxLimit);

        return left || right;
    }
public:
    bool verifyPreorder(vector<int>& preorder) {
        int i = 0;
        return dfs(preorder, i, INT_MIN, INT_MAX);
        
    }
};
