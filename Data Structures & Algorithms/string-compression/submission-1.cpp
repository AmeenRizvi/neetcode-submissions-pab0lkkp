class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        string s = "";
        int i = 0, k = 0;

        while(i < n)
        {
            int j = i;
            while(j < n && chars[i] == chars[j])
            {
                j++;
            }
            chars[k++] = chars[i];
            if(j-i > 1)
            {
                string cnt = to_string(j-i);
                for(char c : cnt)
                {
                    chars[k++] = c;
                }
            }
            i = j;
        }

        
        return k;
        
    }
};