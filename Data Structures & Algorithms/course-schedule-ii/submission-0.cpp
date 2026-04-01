class Solution {
    bool dfs(int node, unordered_set<int>&vis, unordered_set<int>&dfsVis,
    stack<int>&st, unordered_map<int, vector<int>> &adjList)
    {
        vis.insert(node);
        dfsVis.insert(node);
        for(auto nbr : adjList[node])
        {
            if(vis.count(nbr) == 0)
            {
                if( dfs(nbr, vis, dfsVis, st, adjList) )
                    return true;
            }
            else if(dfsVis.count(nbr))
            {
                return true;
            }
        }
        dfsVis.erase(node);
        st.push(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>adjList;
        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjList[u].push_back(v);
        }

        unordered_set<int>vis;
        unordered_set<int>dfsVis;
        stack<int>st;
        for(int i = 0; i < numCourses; i++)
        {
            if(vis.count(i) == 0)
            {
                if( dfs(i, vis, dfsVis, st, adjList) )
                    return {};
            }
            
        }

        vector<int>res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        
        reverse(res.begin(), res.end());
        return res;
        
    }
};
