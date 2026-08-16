/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int>start, end;
        for(auto &i : intervals)
        {
            start.push_back(i.start);
            end.push_back(i.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int n = intervals.size();
        int ans = 0, l = 0, r = 0, count = 0;
        while(l < n)
        {
            if(start[l] < end[r])
            {
                l++;
                count++;
            }
            else
            {
                r++;
                count--;
            }
            ans = max(ans, count);
        }
        return ans;
        
    }
};
