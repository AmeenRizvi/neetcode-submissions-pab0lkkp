class Solution {
    bool dfs(int node, int en, vector<vector<int>>&adjList, unordered_set<int>&visited )
    {
        visited.insert(node);
        if(node == en)
        {
            return true;
        }

        for(auto nbr : adjList[node])
        {
            if(!visited.count(nbr))
            {
                if(dfs(nbr, en, adjList, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>adjList(numCourses);

        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[u].push_back(v);
        }

        vector<bool>answer;

        for(int j = 0; j < queries.size(); j++)
        {
            int st = queries[j][0];
            int en = queries[j][1];

            unordered_set<int>visited;
            bool ans = dfs(st, en, adjList, visited);
            answer.push_back(ans);
        }
        return answer;
        
    }
};