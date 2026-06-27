class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>mp;

        for(char c : chars)
        {
            mp[c]++;
        }

        int ans = 0;
        for(auto &word : words)
        {
            unordered_map<char,int>dict = mp;
            bool takeWord = true;
            for(auto &c : word)
            {
                if(dict.count(c) == 0)
                {
                    takeWord = false;
                    break;
                }
                else
                {
                    dict[c]--;
                    if(dict[c] == 0)
                    {
                        dict.erase(c);
                    }
                }
            }

            if(takeWord) ans += word.size();
        }
        return ans;
        
    }
};