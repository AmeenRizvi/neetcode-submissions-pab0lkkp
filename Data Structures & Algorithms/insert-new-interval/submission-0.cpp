class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>>ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < n; i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int j = i;
            if(!ans.empty() && ans.back()[1] >= end)
                continue;
            while(j < n && end >= intervals[j][0])
            {
                end = max(end, intervals[j][1]);
                j++;
            }
            ans.push_back({start, end});
        }
        return ans;
        
    }
};
