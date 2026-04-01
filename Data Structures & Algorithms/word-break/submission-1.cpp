class Solution {
    bool solve(int idx, string s, unordered_set<string>&wordSet, vector<int>&dp)
    {
        if(idx == s.size())
            return true;
        if(dp[idx] != -1)
            return dp[idx];
        
        string temp = "";
        for(int i = idx; i < s.size(); i++)
        {
            temp = temp + s[i];
            if(wordSet.find(temp) != wordSet.end())
            {
                if(solve(i+1, s, wordSet, dp))
                {
                    dp[i+1] = 1;
                    return true;
                }
            }
        }
        return dp[idx] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordSet(wordDict.begin(), wordDict.end());
        vector<int>dp(s.size()+1, -1);
        return solve(0, s, wordSet, dp);
        
    }
};
