class Solution {
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>&vis, string &s, char dir)
    {
        if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j] == 0 
        || vis[i][j])
            return;
        vis[i][j] = true;

        s += dir;
        dfs(i+1, j, grid, vis, s,'D');
        dfs(i-1, j, grid, vis, s,'U');
        dfs(i, j+1, grid, vis, s,'R');
        dfs(i, j-1, grid, vis, s,'L');
        s += '0';

    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<bool>>vis(m, vector<bool>(n, false));
        unordered_set<string>st;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1 && !vis[i][j] )
                {
                    string s = "";
                    dfs(i, j, grid, vis, s,'0');
                    st.insert(s);
                }
            }
        }

        return st.size();
        
    }
};
