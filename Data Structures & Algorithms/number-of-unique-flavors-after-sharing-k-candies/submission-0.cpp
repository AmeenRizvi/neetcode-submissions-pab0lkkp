class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        int n = candies.size();
        unordered_map<int,int>freq;
        int maxCandies = 0;

        for(int i = 0; i < n; i++)
        {
            freq[candies[i]]++;
        }
        // if(k == 0) return freq.size();

        for(int i = 0; i < k; i++)
        {
            freq[candies[i]]--;
            if(freq[candies[i]] == 0)
            {
                freq.erase(candies[i]);
            }
        }
        maxCandies = max(maxCandies, (int)freq.size());

        for(int i = k; i < n; i++)
        {
            freq[candies[i-k]]++;
            freq[candies[i]]--;
            if(freq[candies[i]] == 0)
            {
                freq.erase(candies[i]);
            }
            maxCandies = max(maxCandies, (int)freq.size());
        }
        return maxCandies;


    }
};
