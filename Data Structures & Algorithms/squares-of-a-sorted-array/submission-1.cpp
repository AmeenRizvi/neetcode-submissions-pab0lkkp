class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;

        vector<int>ans(n);
        for(int k = n-1; k >= 0; k--)
        {
            if(abs(nums[left]) > abs(nums[right]))
            {
                ans[k] =  nums[left]*nums[left] ;
                left++;
            }
            else
            {
                ans[k] =  nums[right]*nums[right] ;
                right--;
            }
        }
        return ans;
        
    }
};