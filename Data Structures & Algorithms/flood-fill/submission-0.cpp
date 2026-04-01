class Solution {
    void dfs(int i, int j, vector<vector<int>>& image, int org, int color)
    {
        if(i >= image.size() || i < 0 || j >= image[0].size() || j < 0 || image[i][j] != org)
        {
            return;
        }
        image[i][j] = color;
        dfs(i+1, j, image, org, color);
        dfs(i-1, j, image, org, color);
        dfs(i, j+1, image, org, color);
        dfs(i, j-1, image, org, color);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int org = image[sr][sc];
        if(org == color) return image;

        dfs(sr, sc, image, org, color);
        return image;
        
    }
};