class Solution {
private:
    bool isChar(char c)
    {
        return c >= 'a' && c <= 'z';
    }
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n = word.size(), m = abbr.size();

        int i = 0, j = 0;

        while(j < m)
        {
            if(isChar(abbr[j] ) )
            {
                if(i >= n || word[i] != abbr[j])
                {
                    return false;
                }
                i++;
                j++;
            }
            else
            {
                int num = 0;
                if(abbr[j] == '0') return false;

                while(j < m && !isChar(abbr[j]) )
                {
                    num = num*10 + (abbr[j]-'0');
                    j++;
                }
                if(i + num > n)
                {
                    return false;
                }
                i = i + num;
            }
        }

        return i == n;
        
    }
};