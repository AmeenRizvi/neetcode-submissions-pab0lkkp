class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        unordered_set<int>s;

        for(int num : nums)
        {
            mp[num]++;
            if(mp[num] > n/3)
            {
                s.insert(num);
            }
        }

        vector<int>ans(s.begin(), s.end());
        return ans;
    }
};