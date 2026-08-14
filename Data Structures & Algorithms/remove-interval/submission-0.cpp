class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int n = intervals.size();
        vector<vector<int>>ans;

        
        for(int i = 0; i < n; i++)
        {
            int st = intervals[i][0];
            int en = intervals[i][1];

            if(st < toBeRemoved[0])
            {
                int currentEn = min(en, toBeRemoved[0]);
                ans.push_back({st, currentEn});
            }

            if(en > toBeRemoved[1])
            {
                int newStart = max(st, toBeRemoved[1]);
                if(newStart < en)
                    ans.push_back({newStart, en});
            }
        }
        return ans;
    }
};
