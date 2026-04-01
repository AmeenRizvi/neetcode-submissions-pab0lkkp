class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool>row(matrix.size());
        vector<bool>col(matrix[0].size());

        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0;  j < matrix[i].size(); j++ )
            {
                if(matrix[i][j] == 0)
                {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for(int i = 0; i < row.size(); i++)
        {
            if(row[i])
            {
                for(int j = 0; j < matrix[0].size(); j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 0; j < col.size(); j++)
        {
            if(col[j])
            {
                for(int i = 0; i < matrix.size(); i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};
