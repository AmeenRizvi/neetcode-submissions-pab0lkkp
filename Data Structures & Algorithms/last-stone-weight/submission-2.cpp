class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        while(stones.size() > 1)
        {
            sort(stones.begin(), stones.end());
            int n = stones.size();
            int x = stones[n-2];
            int y = stones[n-1];

            int cur = y - x;
            stones.pop_back();
            stones.pop_back(); 
            if(cur > 0)
            {
                stones.push_back(cur);
            }
        }

        return stones.size() == 0 ? 0 : stones[0];
        
    }
};
