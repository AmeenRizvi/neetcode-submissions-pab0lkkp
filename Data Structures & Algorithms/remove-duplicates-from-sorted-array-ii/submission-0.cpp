class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int>freq;
        vector<int>arr;
        int n = nums.size();
        int k = 0;

        for(int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
            if(freq[nums[i]] <= 2)
            {
                arr.push_back(nums[i]);
                k++;
            }
        }

        for(int i = 0; i < k; i++)
        {
            nums[i] = arr[i];
        }

        return k;
        
    }
};