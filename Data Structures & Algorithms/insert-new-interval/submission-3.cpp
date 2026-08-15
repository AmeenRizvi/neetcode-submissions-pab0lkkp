class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;

        vector<vector<int>>ans;
        while(i < n && intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }

        int s = newInterval[0];
        int e = newInterval[1];

        while(i < n && newInterval[1] >= intervals[i][0])
        {
            s = min(intervals[i][0], s);
            e = max(intervals[i][1], e);
            i++;
        }
        ans.push_back({s, e});

        while(i < n )
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
