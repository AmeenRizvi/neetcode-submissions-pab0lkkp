class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int ones = 0;
        for(char c : s)
        {
            if(c == '1')
                ones++;
        }

        string res((ones-1), '1');
        res += string(n-ones, '0');
        res += '1';

        return res;
        
    }
};