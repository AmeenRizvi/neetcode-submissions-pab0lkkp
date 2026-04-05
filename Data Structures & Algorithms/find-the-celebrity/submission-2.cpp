/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<int>inDegree(n), outDegree(n);  // n people, 0 to n-1

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i != j && knows(i, j))  
                // a person will always know themselves but here we want to know if they know others
                // graph[i][j] == 1 , i knows j
                {
                    inDegree[j]++;
                    outDegree[i]++;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(inDegree[i] == n-1 && outDegree[i] == 0)  // celebrity condition
            {
                return i;
            }
        }

        return -1;  // if no answer found
        
    }
};
