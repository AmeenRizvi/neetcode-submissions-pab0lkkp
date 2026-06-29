class Solution {
public:
    bool wordPattern(string pattern, string s) {

        int n = pattern.size();

        vector<string>words;
        stringstream ss(s);
        string word;
        while(ss >> word)
        {
            words.push_back(word);
        }

        if(pattern.size() != words.size()) return false;

        unordered_map<char,string>matching1;
        unordered_map<string, char>matching2;
        

        for(int i = 0; i < n; i++)
        {
            if( matching1.count( pattern[i] ) != 0 )
            {
                if(matching1[ pattern[i] ] == words[i] )
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                matching1[ pattern[i] ] = words[i];
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            if(matching2.count( words[i] ) )
            {
                if(matching2[ words[i] ] == pattern[i])
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                matching2[ words[i] ] = pattern[i];
            }
        }

        return true;
        
    }
};