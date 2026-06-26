class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int>mp;

        for(char c : allowed)
        {
            mp[c]++;
        }

        int ans = 0;
        for(auto &word : words)
        {
            bool flag = true;
            for(char c : word)
            {
                if(mp.find(c) == mp.end())
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                ans++;
            }
        }
        return ans;
        
    }
};