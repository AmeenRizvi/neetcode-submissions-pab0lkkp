class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        string s = "";
        int i = 0;

        while(i < n)
        {
            int j = i;
            while(j < n && chars[i] == chars[j])
            {
                j++;
            }
            s += chars[i];
            if(j-i > 1)
            {
                s += to_string(j-i);
            }
            i = j;
        }

        int k = s.size();
        
        for(int i = 0; i < k ; i++)
        {
            chars[i] = s[i];
        }
        return k;
        
    }
};