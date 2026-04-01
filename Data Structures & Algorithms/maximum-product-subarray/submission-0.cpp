class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = INT_MIN, n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int prod = 1;
            for(int j = i; j < n; j++)
            {
                prod = prod*nums[j];
                maxProd = max(maxProd, prod);
            }
        }
        return maxProd;

        
    }
};
