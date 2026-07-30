class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if(originalColor == color)
        {
            return image;
        }

        int directions[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
        
        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        while(!q.empty() )
        {
            auto [i, j] = q.front();
            q.pop();

            for(auto &dir : directions)
            {
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if(new_i >= 0 && new_i < image.size() && new_j >= 0 && new_j < image[0].size())
                {
                    if(image[new_i][new_j] == originalColor)
                    {
                        q.push({new_i, new_j});
                        image[new_i][new_j] = color;
                    }
                }
            }
        }
        return image;
        
    }
};