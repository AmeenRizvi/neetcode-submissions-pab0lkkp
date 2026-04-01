class Solution {
public:
    int maxDepth(string s) {
        int maxAns = 0, len = 0;
        for(char c : s)
        {
            if(c == '(')
            {
                len++;
                maxAns = max(maxAns, len);
            }
            else if(c == ')')
            {
                len--;
            }
        }
        return maxAns;
        
    }
};