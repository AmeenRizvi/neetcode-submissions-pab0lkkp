class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>curr(n+1, 0);
        vector<int>forw(n+1, 0);

        for(int i = m-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                if(i == m-1 && j == n-1)
                    curr[j] = 1;
                else
                {
                    int p1 = forw[j];
                    int p2 = j+1 < n ? curr[j+1] : 0;

                    curr[j] = p1+p2;
                }
            }
            forw = curr;
        }
        return forw[0];
        
    }
};
