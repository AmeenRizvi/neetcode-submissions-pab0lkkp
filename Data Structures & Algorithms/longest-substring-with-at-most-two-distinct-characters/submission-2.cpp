class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        unordered_map<int,int>mp;
        int l = 0, maxLen = 0;

        for(int r = 0; r < n; r++)
        {
            mp[s[r]]++;
            while(mp.size() > 2)
            {
                mp[s[l]]--;
                if(mp[s[l]] == 0)
                {
                    mp.erase(s[l]);
                }
                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
        
        
    }
};