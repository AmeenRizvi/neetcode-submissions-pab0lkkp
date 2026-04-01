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
        vector<int>start;
        vector<int>end;

        for(int i = 0; i < intervals.size(); i++)
        {
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int count = 0, maxCount = 0, s = 0, e = 0, n = start.size();

        while(s < n)
        {
            if(start[s] < end[e])
            {
                s += 1;
                count += 1;
            }
            else
            {
                e += 1;
                count -= 1;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
