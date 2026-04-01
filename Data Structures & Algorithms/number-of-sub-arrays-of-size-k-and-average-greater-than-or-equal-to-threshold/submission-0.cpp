class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0, ans = 0, n = arr.size();
        for(int i = 0; i < k; i++)
        {
            sum += arr[i];
        }
        if( (double)sum/k >= threshold)
        {
            ans++;
        }

        for(int i = k; i < n; i++)
        {
            sum += arr[i];
            sum -= arr[i-k];

            if( (double)sum/k >= threshold)
            {
                ans++;
            }
        }
        return ans;
        
    }
};