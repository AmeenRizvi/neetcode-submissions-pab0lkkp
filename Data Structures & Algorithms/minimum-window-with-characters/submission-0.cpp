class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>mp;
        int n = s.size(), m = t.size();
        if(n < m)
            return "";
        
        for(int i = 0; i < m; i++)
        {
            mp[t[i]]++;
        }

        int l = 0, minLen = INT_MAX, starti = -1, counter = t.size();
        for(int i = 0; i < n; i++)
        {
            if(mp[s[i]] > 0)
            {
                counter--;
            }
            mp[s[i]]--;
            
            while(counter == 0)
            {
                if(i-l+1 < minLen)
                {
                    minLen = i-l+1;
                    starti = l;
                }    
                if(mp[s[l]] == 0)
                    counter++;
                mp[s[l]]++;
                l++;
                
            }

        }
        return minLen == INT_MAX ? "" : s.substr(starti, minLen);

        

        
    }
};
