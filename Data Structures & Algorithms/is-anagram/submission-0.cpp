class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        
        if(n != m)
            return false;
        unordered_map<int, int>mp1;
        unordered_map<int, int>mp2;

        for(int i = 0; i < n; i++)
        {
            mp1[s[i]]++;
        }
        for(int j = 0; j < m; j++)
        {
            mp2[t[j]]++;
        }

        if(mp1 == mp2)
            return true;
        return false;
        
    }
};
