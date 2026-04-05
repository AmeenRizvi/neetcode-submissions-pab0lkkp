/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<int>inDegree(n), outDegree(n);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i != j && knows(i, j))
                {
                    inDegree[j]++;
                    outDegree[i]++;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(inDegree[i] == n-1 && outDegree[i] == 0)
            {
                return i;
            }
        }

        return -1;
        
    }
};
