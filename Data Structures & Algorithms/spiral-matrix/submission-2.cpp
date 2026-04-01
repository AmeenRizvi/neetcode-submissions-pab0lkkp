class Solution {
    void dfs(int i, int j, int di, int dj, int m, int n, vector<vector<int>>& matrix,
     vector<int>&ans)
    {
        if(m == 0 || n == 0)
            return;

        for(int k = 0; k < n; k++)
        {
            i += di;
            j += dj;
            ans.push_back(matrix[i][j]);
        }
        dfs(i, j, dj, -di, n, m-1, matrix, ans);

    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m = matrix.size(), n = matrix[0].size();
        dfs(0, -1, 0, 1, m, n, matrix, ans);
        return ans;
    }
};
