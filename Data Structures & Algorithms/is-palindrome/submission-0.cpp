class Solution {
public:
    bool isPalindrome(string s) {
        string newStr = "";
        for(char ch : s)
        {
            if(isalnum(ch))
            {
                newStr += tolower(ch);
            }
        }
        return newStr == string(newStr.rbegin(), newStr.rend());
        
    }
};
