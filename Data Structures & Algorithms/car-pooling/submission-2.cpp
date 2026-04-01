class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<pair<int,int>> points;

        for(const auto& trip : trips)
        {
            int passengers = trip[0], st = trip[1], en = trip[2];

            points.emplace_back(st, passengers);
            points.emplace_back(en, -passengers);
        }

        sort(points.begin(), points.end(), [](const pair<int,int>&a, const pair<int,int>&b)
        {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });

        int curPass = 0;
        for(const auto& point : points)
        {
            curPass += point.second;
            if(curPass > capacity)
            {
                return false;
            }
        }

        return true;
        
    }
};