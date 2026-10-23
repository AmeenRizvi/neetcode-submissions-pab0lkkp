class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        unordered_map<int,int>mp;
        int l = 0;
        for(int r = 0; r < n; r++)
        {
            mp[s[r]]++;
            while(r-l+1 >= 3 && mp.size() == 3)
            {
                ans += n-r;
                mp[s[l]]--;
                if(mp[s[l]] == 0)
                {
                    mp.erase(s[l]);
                }
                l++;
            }
        }

        return ans;

    }
};
