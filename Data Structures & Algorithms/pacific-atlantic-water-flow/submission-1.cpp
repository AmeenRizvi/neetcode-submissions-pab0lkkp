class Solution {
    int rows, cols;
    int directions[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>&vis)
    {
        if(vis[i][j] == true)
        {
            return;
        }
        vis[i][j] = true;

        for(auto &dir : directions)
        {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(new_i >= 0 && new_i < rows && new_j >= 0 && new_j < cols &&
            heights[i][j] <= heights[new_i][new_j])
            {
                dfs(new_i, new_j, heights, vis);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>>pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>>atlantic(rows, vector<bool>(cols, false));

        for(int i = 0; i < rows; i++)
        {
            dfs(i, 0, heights, pacific);
            dfs(i, cols-1, heights, atlantic);
        }
        for(int j = 0; j < cols; j++)
        {
            dfs(0, j, heights, pacific);
            dfs(rows-1, j, heights, atlantic);
        }

        vector<vector<int>>ans;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;

        
        
    }
};
