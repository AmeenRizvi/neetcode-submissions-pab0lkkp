class Solution {
public:
    int equalCountSubstrings(string s, int count) {
        int n = s.size();
        int ans = 0;

        
        for(int k = 1; k <= 26 && k*count <= n; k++)
        {
            int windowLen = k*count;
            vector<int>freq(26, 0);
            int exactCount = 0;

            for(int i = 0; i < n; i++)
            {
                freq[s[i]-'a']++;
                if(freq[s[i]-'a'] == count)
                {
                    exactCount++;
                }
                else if(freq[s[i]-'a'] == count + 1)
                {
                    exactCount--;                
                }

                if(i >= windowLen)
                {
                    char out = s[i - windowLen];
                    if(freq[out - 'a'] == count)
                    {
                        exactCount--;
                    }
                    else if(freq[out - 'a'] == count + 1)
                    {
                        exactCount++;
                    }
                    freq[out-'a']--;
                }
                if(i >= windowLen - 1 && exactCount == k)
                {
                    ans++;
                }
            }
        }
        return ans;

    }
};
