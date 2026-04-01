class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        while(stones.size() > 1)
        {
            sort(stones.begin(), stones.end());
            int n = stones.size();
            int x = stones[n-2];
            int y = stones[n-1];

            if(x == y)
            {
                stones.resize(n-2);
            }
            else
            {
                y = y - x;
                stones.resize(n-1);
                stones[n-2] = y;
            }
        }

        return stones.size() == 0 ? 0 : stones[0];
        
    }
};
