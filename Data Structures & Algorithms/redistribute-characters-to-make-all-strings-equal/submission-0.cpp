class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int m = words.size();
        unordered_map<char,int>freq;

        for(auto &word : words)
        {
            for(auto &c : word)
            {
                freq[c]++;
            }
        }

        for(auto&[ch, charFreq] : freq)
        {
            if(charFreq % m != 0)
            {
                return false;
            }
        }
        return true;
        
    }
};