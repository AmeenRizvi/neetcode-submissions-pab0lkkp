class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), maxLen = INT_MIN;

        unordered_map<char, int>mp;
        int l = 0;
        for(int r = 0; r < n; r++)
        {
            mp[s[r]]++;
            while(l < r && mp[s[r]] >= 2)
            {
                mp[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen == INT_MIN ? 0 : maxLen;
        
    }
};
