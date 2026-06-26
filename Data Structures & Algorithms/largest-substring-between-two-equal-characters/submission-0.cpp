class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        unordered_map<char,int>mp;
        int maxLen = -1;

        for(int i = 0; i < n; i++)
        {
            if(mp.count( s[i] ))
            {
                int len = i - mp[ s[i] ] - 1;
                maxLen = max(maxLen, len);
            }
            else
            {
                mp[ s[i] ] = i;
            }
        }
        return maxLen;
        
    }
};