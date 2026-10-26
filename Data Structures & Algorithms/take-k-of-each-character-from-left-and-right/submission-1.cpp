class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k == 0) return 0;
        int n = s.size();
        unordered_map<char,int>freq;

        for(int i = 0; i < n; i++)
        {
            freq[s[i]]++;
        }
        if(freq.size() < 3) return -1;

        unordered_map<char,int>maxFreq;
        for(auto &p : freq)
        {
            if(p.second < k)
            {
                return -1;
            }
            maxFreq[p.first] = p.second - k;
        }

        int l = 0, r = 0, maxLen = 0;
        unordered_map<char,int>mp;
        while(r < n)
        {
            mp[s[r]]++;
            while(mp[s[r]] > maxFreq[s[r]])
            {
                mp[s[l]]--;
                if(mp[s[l]] == 0)
                {
                    mp.erase(s[l]);
                }
                l++;
            }
            int len = r-l+1;
            maxLen = max(maxLen, len);
            r++;
        }
        return n-maxLen;

    }
};
