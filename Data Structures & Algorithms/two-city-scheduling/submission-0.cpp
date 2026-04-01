class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<vector<int>>diffs;
        for(auto &cost : costs)
        {
            diffs.push_back({cost[1]-cost[0], cost[0], cost[1]});
        }

        sort(diffs.begin(), diffs.end());
        int res = 0;
        for(int i = 0; i < diffs.size(); i++)
        {
            if(i < diffs.size() / 2)
            {
                res += diffs[i][2];
            }
            else
            {
                res += diffs[i][1];
            }
        }
        return res;
        
    }
};