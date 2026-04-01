class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0, n = s.size();
        for(int i = 0; i < n-1; i++)
        {
            if(s[i] == '1')
            {
                ones++;
            }
        }
        cout << ones << endl;

        
        if(s[n-1] != '1')
        {
            s[n-1] = '1';
            ones--;
        }

        for(int i = 0; i < n-1; i++)
        {
            if(ones > 0)
            {
                s[i] = '1';
                ones--;
            }
            else
            {
                s[i] = '0';
            }
        }
        return s;
        
    }
};