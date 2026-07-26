class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totalSum = 0;
        for(int stone : stones)
        {
            totalSum += stone;
        }
        // vector<vector<int>>dp(n+1, vector<int>(totalSum/2+1, 0));
        vector<int>row(totalSum/2+1, 0);
        vector<int>nextRow(totalSum/2+1, 0);

        for(int i = n-1; i >= 0; i--)
        {
            for(int sum = totalSum/2; sum >= 0; sum--)
            {
                int take = 0;
                if(sum + stones[i] <= totalSum/2)
                {
                    take = stones[i] + nextRow[sum + stones[i]];
                }
                int dontTake = nextRow[sum];
                row[sum] = max(take, dontTake);
            }
            nextRow = row;
        }

        int temp = nextRow[0];
        return totalSum - 2*temp;
    }
};