class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size(), n = picture[0].size();

        vector<int>rowCount(m, 0);
        vector<int>colCount(n, 0);

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(picture[i][j] == 'B')
                {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(picture[i][j] == 'B' && rowCount[i] == 1 && colCount[j] == 1)
                {
                    ans++;
                }
            }
        }
        return ans;
        
    }
};
