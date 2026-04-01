class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int m = 0;
        for(int i = 0; i < n; i++)
        {
            m = max(m, piles[i]);
        }

        int l = 1, r = m;

        int rate = r;
        while(l <= r)
        {
            int mid = (l+r)/2;
            long long time = 0;
            for(int pile : piles)
            {
                time += ceil((double)pile/mid);
            }

            if(time <= h)
            {
                rate = mid;
                r = mid - 1;
            } 
            else
            {
                l = mid + 1;
            }
        }
        return rate;

        
    }
};
