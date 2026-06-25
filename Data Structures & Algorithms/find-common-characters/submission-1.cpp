class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>arr(26, 1e9);

        for(auto &word : words)
        {
            vector<int>curr(26, 0);
            for(char c : word)
            {
                curr[c - 'a']++;
            }

            for(int i = 0; i < 26; i++)
            {
                arr[i] = min(arr[i], curr[i]);
            }
        }

        vector<string> ans;
        for(int i = 0; i < 26; i++)
        {
            for(int j = 0; j < arr[i]; j++)
            {
                ans.push_back(string(1, i+'a'));
            }
        }
        return ans;
        
    }
};