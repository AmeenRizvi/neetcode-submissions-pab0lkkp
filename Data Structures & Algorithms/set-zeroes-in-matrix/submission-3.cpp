class Solution {
    void setZero(int r, int c, vector<vector<int>>&temp)
    {
        int m = temp.size(), n = temp[0].size();

        for(int j = 0; j < n; j++)
        {
            temp[r][j] = 0;
        }
        for(int i = 0; i < m; i++)
        {
            temp[i][c] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>>temp(m, vector<int>(n,0));
        temp = matrix;


        for(int i = 0; i < m; i++)
        {
            for(int j = 0;  j <n; j++)
            {
                if(matrix[i][j] == 0)
                    setZero(i, j, temp);
            }
        }

        matrix = temp;
        
    }
};
