class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();
        unordered_map<char,int>freq;
        int maxOdd = 0;
        int minEven = n-1;

        for(char c : s)
        {
            freq[c]++;
        }

        for(auto &p : freq)
        {
            if(p.second % 2 == 1)
            {
                maxOdd = max(maxOdd, p.second);
            }
            else
            {
                minEven = min(minEven, p.second);
            }
        }

        return maxOdd - minEven;
    }
};