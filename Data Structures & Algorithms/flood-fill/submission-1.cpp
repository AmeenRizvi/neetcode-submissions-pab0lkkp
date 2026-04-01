class Solution {
    int directions[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int org = image[sr][sc];
        if(org == color) return image;

        queue<pair<int,int>>q;
        q.push({sr, sc});
        image[sr][sc] = color;

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int newX = x + directions[i][0];
                int newY = y + directions[i][1];

                if(newX < 0 || newX >= image.size() || newY < 0 || newY >= image[0].size()
                || image[newX][newY] != org)
                {
                    continue;
                }
                else
                {
                    q.push({newX, newY});
                    image[newX][newY] = color;
                }
            }
        }
        return image;
        
    }
};