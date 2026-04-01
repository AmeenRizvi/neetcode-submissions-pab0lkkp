class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);

        for(auto&interval : intervals)
        {
            int start = interval[0];
            int end = interval[1];
            int lastEnd = ans.back()[1];

            if(start <= lastEnd)
                ans.back()[1] = max(lastEnd, end);
            else
                ans.push_back({start, end});
        }
        return ans;
        
    }
};
