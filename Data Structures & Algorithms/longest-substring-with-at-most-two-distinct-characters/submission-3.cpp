class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        int l = 0, r = 0, maxLen = 0;
        unordered_map<char,int>freq;

        while(r < n)
        {
            freq[s[r]]++;
            while(freq.size() > 2)
            {
                freq[s[l]]--;
                if(freq[s[l]] == 0)
                {
                    freq.erase(s[l]);
                }
                l++;
            }
            int len = r-l+1;
            maxLen = max(maxLen, len);
            r++;
        }
        return maxLen;
        
    }
};