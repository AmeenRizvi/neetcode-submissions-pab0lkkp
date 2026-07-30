class Solution {
    int rows, cols;

    void dfs(int i, int j, vector<vector<int>>& image, int color, int originalColor)
    {
        if(i >= rows || i < 0 || j >= cols || j < 0 || image[i][j] != originalColor)
        {
            return;
        }

        image[i][j] = color;

        dfs(i+1, j, image, color, originalColor);
        dfs(i-1, j, image, color, originalColor);
        dfs(i, j+1, image, color, originalColor);
        dfs(i, j-1, image, color, originalColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if(originalColor == color)
        {
            return image;
        }

        rows = image.size();
        cols = image[0].size();

        dfs(sr, sc, image, color, originalColor);

        return image;
        
    }
};