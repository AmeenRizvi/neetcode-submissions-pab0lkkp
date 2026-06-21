class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int n = keyboard.size(), m = word.size();
        if(n == 0) return 0;
        unordered_map<char,int>mp;
    
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            mp[ keyboard[i] ] = i;
        }

        ans += mp[ word[0] ];
        for(int i = 1; i < m; i++)
        {
            int currIdx = mp[ word[i] ];
            int beforeIdx = mp[ word[i-1] ];
            ans += abs(currIdx - beforeIdx);
        }
        return ans;
    }
};
