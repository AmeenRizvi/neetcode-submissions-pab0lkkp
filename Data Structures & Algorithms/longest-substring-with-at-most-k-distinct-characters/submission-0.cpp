class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        int l = 0, maxLen = 0;
        unordered_map<int,int>mp;

        for(int r = 0; r < n; r++)
        {
            mp[s[r]]++;
            while(mp.size() > k)
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
