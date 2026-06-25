class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int>mp;
        for(char c : text)
        {
            if( string("balon").find(c) != string::npos  )
            {
                mp[c]++;
            }
        }

        if(mp.size() < 5)
        {
            return 0;
        }

        mp['l'] /= 2;
        mp['o'] /= 2;

        return min({mp['b'], mp['a'], mp['l'], mp['o'], mp['n'] });
    }
};