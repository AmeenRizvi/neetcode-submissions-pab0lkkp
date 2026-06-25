class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>arr(26, 0);
        for(char ch : text)
        {
            arr[ch - 'a']++;
        }

        string temp = "balloon";

        int ans = 1e9;
        for(char c : temp)
        {
            if(c == 'l' || c == 'o')
            {
                ans = min(ans, arr[c-'a']/2);
            }
            else
            {
                ans = min(ans, arr[c-'a']);
            }
        }
        return ans;        
    }
};