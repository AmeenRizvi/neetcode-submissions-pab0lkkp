class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int countR[26] = {};
        int countM[26] = {};

        for(char c : ransomNote)
        {
            countR[c-'a']++;
        }
        for(char c : magazine)
        {
            countM[c-'a']++;
        }

        for(int i = 0; i < 26; i++)
        {
            if(countM[i] < countR[i])
                return false;
        }
        return true;
        
    }
};