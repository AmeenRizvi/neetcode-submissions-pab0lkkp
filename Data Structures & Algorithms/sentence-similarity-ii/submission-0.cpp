class Solution {
    bool dfs(string node, string s2, unordered_map<string, vector<string>>&adjList,
    unordered_set<string>&visit )
    {
        visit.insert(node);
        if(node == s2) return true;

        for(auto nbr : adjList[node])
        {
            if(!visit.count(nbr))
            {
                if( dfs(nbr, s2, adjList, visit) )
                {
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size() != sentence2.size()) return false;

        unordered_map<string, vector<string>>adjList;

        for(auto &p : similarPairs)
        {
            string u = p[0];
            string v = p[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        for(int i = 0; i < sentence1.size(); i++)
        {
            string w1 = sentence1[i];
            unordered_set<string>visit;
            if(!dfs(w1, sentence2[i], adjList, visit) )
            {
                return false;
            }
        }
        return true;

        
        
    }
};
