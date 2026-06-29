class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        unordered_map<int,int>numToFreq;
        int m = mat.size(), n = mat[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                numToFreq[ mat[i][j] ]++;
            }
        }

        int ans = INT_MAX;
        for(auto &[num, freq] : numToFreq)
        {
            if(freq == m)
            {
                ans = min(ans, num);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
