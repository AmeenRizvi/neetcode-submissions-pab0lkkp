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
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        for(int i = 0; i < n; i++)
        {
            int start = intervals[i].start;
            int end = intervals[i].end;
            for(int j = i+1; j<n; j++)
            {
                Interval B = intervals[j];
                if(min(end, B.end) > max(start, B.start))
                    return false;

            }
        }
        return true;
        
    }
};
