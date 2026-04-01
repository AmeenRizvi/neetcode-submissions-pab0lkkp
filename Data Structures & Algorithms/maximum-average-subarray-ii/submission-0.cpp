class Solution {
    bool check(vector<int>& nums, double mid, int k)
    {
        double sum = 0, prev = 0, min_sum = 0;

        for(int i = 0; i < k; i++)
            sum += nums[i] - mid;
        
        if(sum >= 0)
            return true;
        
        for(int i = k; i < nums.size(); i++)
        {
            sum += nums[i] - mid;
            prev += nums[i-k] - mid;
            min_sum = min(prev, min_sum);
            if(sum >= min_sum)
                return true;
        }
        return false;
    }
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max_val = INT_MIN;
        double min_val = INT_MAX;

        for(int n : nums)
        {
            max_val = max(max_val, (double)n);
            min_val = min(min_val, (double)n);
        }

        double prev_mid = max_val;
        double error = INT_MAX;

        while(error > 0.00001)
        {
            double mid = (max_val+min_val)*0.5;
            if(check(nums, mid, k))
                min_val = mid;
            else
                max_val = mid;
            error = abs(prev_mid - mid);
            prev_mid = mid;
        }
        return min_val;
        
    }
};
