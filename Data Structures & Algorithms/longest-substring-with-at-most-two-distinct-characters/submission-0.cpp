class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        int l = 0, maxLen = 0;
        unordered_map<int, int>mp;

        for(int r = 0; r < n; r++)
        {
            mp[s[r]]++;
            while(mp.size() > 2)
            {
                mp[s[l]]--;
                if(mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }
            int len = r-l+1;
            maxLen = max(maxLen, len);
        }
        return maxLen;
        
    }
};