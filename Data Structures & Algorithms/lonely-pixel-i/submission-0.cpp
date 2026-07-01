class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size(), n = picture[0].size();
        queue<pair<int,int>>q;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(picture[i][j] == 'B')
                {
                    q.push({i, j});
                }
            }
        }

        int ans = 0;
        while(!q.empty() )
        {
            auto[r, c] = q.front();
            q.pop();

            bool flag1 = true, flag2 = true;
            for(int i = 0; i < m; i++)
            {
                if(i != r && picture[i][c] == 'B')
                {
                    flag1 = false;
                }
            }
            for(int j = 0; j < n; j++)
            {
                if(j != c && picture[r][j] == 'B')
                {
                    flag2 = false;
                }
            }

            if(flag1 && flag2)
            {
                ans++;
            }
        }
        return ans;
        
    }
};
