class Solution {
private:
    bool isVowel(char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' )
        {
            return true;
        }
        return false;
    }
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int vowels = 0, maxVowels = 0;

        for(int i = 0; i < k; i++)
        {
            if(isVowel(s[i]) )
            {
                vowels++;
            }
        }
        maxVowels = max(maxVowels, vowels);

        for(int i = k; i < n; i++)
        {
            if(isVowel(s[i-k]) )
            {
                vowels--;
            }
            if(isVowel(s[i]) )
            {
                vowels++;
            }
            maxVowels = max(maxVowels, vowels);
        }
        return maxVowels;


    }
};
