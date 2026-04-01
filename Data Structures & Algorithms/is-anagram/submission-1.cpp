class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        
        if(n != m)
            return false;
        unordered_map<int, int>mp;

        for(int i = 0; i < n; i++)
        {
            mp[s[i]]++;
        }
        for(int j = 0; j < m; j++)
        {
            mp[t[j]]--;
            if(mp[t[j]] == 0)
                mp.erase(t[j]);
        }

        if(mp.size() == 0)
            return true;
        return false;
        
    }
};
