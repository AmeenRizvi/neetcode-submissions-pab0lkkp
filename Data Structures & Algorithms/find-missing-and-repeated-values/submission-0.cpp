class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int>st;
        int sum = 0;
        int n = grid.size();
        vector<int>ans(2);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int num = grid[i][j];
                if(st.find(num) != st.end())
                {
                    ans[0] = num;
                }
                else
                {
                    st.insert(num);
                    sum += num;
                }
            }
        }

        n = n*n;
        int actualSum = (n*(n+1))/2;
        cout << sum << " " << actualSum;
        int b = actualSum - sum;
        ans[1] = b;

        return ans;
    }
};