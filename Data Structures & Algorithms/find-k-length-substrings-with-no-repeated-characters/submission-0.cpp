class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if(k > 26) return 0;

        int ans = 0;
        int n = s.size();

        int l = 0, r = 0;
        int freq[26] = {0};

        while(r < n)
        {
            freq[s[r]-'a']++;

            while(freq[s[r]-'a'] > 1)
            {
                freq[s[l]-'a']--;
                l++;
            }

            if(r-l+1 == k)
            {
                ans++;
                freq[s[l]-'a']--;
                l++;
            }
            r++;            
        }
        return ans;
    }
};
