class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>mp;
        for(char ch : ransomNote)
        {
            mp[ch]++;
        }

        for(char ch : magazine)
        {
            if(mp.find(ch) != mp.end())
            {
                mp[ch]--;
                if(mp[ch] == 0)
                {
                    mp.erase(ch);
                }
            }
        }

        return mp.size() == 0;
        
    }
};