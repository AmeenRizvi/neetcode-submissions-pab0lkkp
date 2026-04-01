class Solution {
    unordered_set<char>vis;
    unordered_set<char>dfsVis;
    stack<char>st;
    bool dfs(char node, unordered_map<char, unordered_set<char> >&adjList)
    {
        cout << node << endl;
        vis.insert(node);
        dfsVis.insert(node);

        for(auto nbr : adjList[node])
        {
            if(vis.find(nbr) == vis.end())
            {
                if(dfs(nbr, adjList))
                    return true;
            }
            else if(dfsVis.find(nbr) != dfsVis.end())
            {
                return true; // cycle present
            }

        }

        dfsVis.erase(node);
        st.push(node);
        return false;  // cycle not present
    }
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char> >adjList;
        int n = words.size();
        if(n == 1)
            return words[0];

        for( auto word : words)
        {
            for(char ch : word)
            {
                adjList[ch];
            }
        }
        
        for(int i = 0; i < n-1; i++)
        {
            string x = words[i];
            string y = words[i+1];
            int minLen = min(x.size(), y.size());

            if(x.size() > y.size() && x.substr(0,minLen) == y.substr(0, minLen))
                return "";
            
            for(int j = 0; j < minLen; j++)
            {
                if(x[j] != y[j])
                {
                    adjList[x[j]].insert(y[j]);
                    break;
                }
            }
        }

        
        // for(int i = 0; i < 26; i++)
        // {
        //     if(adjList.find('a'+i) != adjList.end() && vis.find('a'+i) == vis.end())
        //     {
        //         bool ans = dfs('a'+i, adjList);
        //         if(ans)
        //             return "";
        //     }
        // }

        for(auto pair : adjList)
        {
            if(vis.find(pair.first) == vis.end())
            {
                if(dfs(pair.first, adjList))
                return "";
            }
        }
            
        string temp = "";
        while(!st.empty())
        {
            temp += st.top();
            st.pop();
        }
        return temp;

        
        
    }
};
