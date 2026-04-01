class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n = nums1.size();
        vector<int>ans(n, -1);

        for(int i = 0; i < n; i++ )
        {
            mp[nums2[i]] = i;
        }

        for(int i = 0; i < n; i++)
        {
            int ele = nums1[i];
            if(mp.find(ele) != mp.end())
            {
                ans[i] = mp[ele];
            }
        }
        return ans;
        
    }
};
