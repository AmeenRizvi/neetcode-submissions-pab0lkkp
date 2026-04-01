class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftProd(n);
        vector<int>rightProd(n);

        leftProd[0] = 1;
        int temp = 1;
        for(int l = 1; l < n; l++)
        {
            temp = temp * nums[l-1];
            leftProd[l] = temp;
        }

        rightProd[n-1] = 1;
        temp = 1;
        for(int r = n-2; r >= 0; r--)
        {
            temp = temp * nums[r+1];
            rightProd[r] = temp;
        }

        vector<int>ans(n);
        for(int i = 0; i < n; i++)
        {
            ans[i] = leftProd[i]*rightProd[i];
        }
        return ans;

    }
};
