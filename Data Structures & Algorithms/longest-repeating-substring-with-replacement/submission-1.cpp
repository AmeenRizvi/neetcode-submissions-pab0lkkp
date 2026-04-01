class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>alpha(26, 0);
        int n = s.size();
        for(int i = 0; i < n; i++ )
        {
            alpha[s[i]-'A']++;
        }

        int maxLen = INT_MIN;

        for(int i = 0; i < 26; i++)
        {
            if(alpha[i] > 0)
            {
                char c = i+'A';
                int l = 0, count = k;
                
                for(int r = 0; r < n; r++)
                {
                    if(s[r] != c)
                        count--;
                    
                    while(l <= r && count < 0)
                    {
                        if(s[l] != c)
                            count++;
                        l++;
                    }

                    maxLen = max(maxLen, r-l+1);
                }

            }
        }
        return maxLen == INT_MIN ? 0 : maxLen;
        
    }
};
