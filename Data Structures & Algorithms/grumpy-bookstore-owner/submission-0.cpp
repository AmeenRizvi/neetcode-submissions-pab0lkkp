class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int l = 0, window = 0, maxWindow = 0, sat = 0;

        for(int r = 0; r < n; r++)
        {
            if(grumpy[r] == 1)
            {
                window += customers[r];
            }
            else
            {
                sat += customers[r];
            }
            if(r - l + 1 > minutes)
            {
                if(grumpy[l] == 1)
                {
                    window -= customers[l];
                }
                l++;
            }
            maxWindow = max(maxWindow, window);
        }
        return maxWindow + sat;
        
    }
};