class Solution {
    int solve(int i, int j, int m, int n)
    {
        if(i >= m || j >= n)
            return 0;
        if(i == m-1 && j == n-1)
            return 1;
        
        int p1 = solve(i+1, j, m, n);
        int p2 = solve(i, j+1, m, n);

        return p1+p2;
    }
public:
    int uniquePaths(int m, int n) {
        return solve(0, 0, m, n);
        
    }
};
