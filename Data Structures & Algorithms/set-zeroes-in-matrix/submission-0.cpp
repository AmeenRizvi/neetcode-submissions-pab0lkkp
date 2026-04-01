class Solution {
    void makeZero(int r, int c, vector<vector<int>>& temp )
    {
        for(int j = 0; j < temp[r].size(); j++)
        {
            temp[r][j] = 0;
        }

        for(int i = 0; i < temp.size(); i++)
        {
            temp[i][c] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>>temp = matrix;

        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0;  j < matrix[i].size(); j++ )
            {
                if(matrix[i][j] == 0)
                    makeZero(i, j, temp);
            }
        }

        matrix = temp;
        
    }
};
