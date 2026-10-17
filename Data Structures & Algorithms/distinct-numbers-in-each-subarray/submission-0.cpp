class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>freq;
        vector<int>ans;


        for(int i = 0; i < k; i++)
        {
            freq[nums[i]]++;
        }
        ans.push_back(freq.size());

        for(int i = k; i < n; i++)
        {
            freq[nums[i-k]]--;
            if(freq[nums[i-k]] == 0)
            {
                freq.erase(nums[i-k]);
            }
            freq[nums[i]]++;

            ans.push_back(freq.size());
        }
        return ans;

    }
};
