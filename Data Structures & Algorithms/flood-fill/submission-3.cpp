class Solution {
    vector<vector<int>>directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orgColor = image[sr][sc];
        if(orgColor == color) return image;
        
        int n = image.size(), m = image[0].size();
        queue<pair<int,int>>q;
        q.push({sr, sc});
        image[sr][sc] = color;

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for(auto &dir : directions)
            {
                int newX = x + dir[0];
                int newY = y + dir[1];

                if(newX >= 0 && newX < n && newY >= 0 && newY < m && image[newX][newY] == orgColor)
                {
                    q.push({newX, newY});
                    image[newX][newY] = color;
                }
            }
        }
        return image;
    }
};