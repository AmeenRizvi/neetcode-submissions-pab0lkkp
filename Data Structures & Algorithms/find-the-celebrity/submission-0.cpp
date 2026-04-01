/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<int>indegree(n);
        vector<int>outdegree(n);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j) continue;
                if( knows(i, j) )
                {
                    outdegree[i]++;
                    indegree[j]++;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == n-1 && outdegree[i] == 0)
            {
                return i;
            }
        }
        return -1;
        
    }
};
