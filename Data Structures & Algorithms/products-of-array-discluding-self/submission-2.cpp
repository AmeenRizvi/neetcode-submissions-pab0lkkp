class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int>ans(n,1);
        
        for(int l = 1; l < n; l++)
        {
            ans[l] = ans[l-1]*nums[l-1]; 
        }

        int temp = 1;
        for(int r = n-2; r >= 0; r--)
        {
            temp = temp * nums[r+1];
            ans[r] *= temp;
        }

        return ans;

    }
};
