class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size() != sentence2.size())
            return false;
        unordered_map<string, vector<string>> dict;

        for(auto &s : similarPairs)
        {
            string w1 = s[0];
            string w2 = s[1];

            dict[w1].push_back(w2);
            dict[w2].push_back(w1);
        }

        int n = sentence1.size();
        for(int i = 0; i < n; i++)
        {
            string w1 = sentence1[i];
            // if(!dict.count(w1))
            // {
            //     return false;
            // }
            bool found = false;
            for(auto nbr : dict[w1])
            {
                if(nbr == sentence2[i])
                {
                    found = true;
                    break;
                }
            }
            if(!found && sentence2[i] != w1) return false;
            
        }
        return true;
    }
};
