class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>passengers(1000, 0);

        for(int i = 0; i < trips.size(); i++)
        {
            int num = trips[i][0];
            int st = trips[i][1];
            int en = trips[i][2];

            for(int j = st; j < en; j++)
            {
                passengers[j] += num;
                if(passengers[j] > capacity)
                    return false;
            }
        }
        return true;
        
    }
};