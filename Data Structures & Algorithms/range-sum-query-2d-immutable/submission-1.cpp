class NumMatrix {
    vector<vector<int>>temp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        temp = vector<vector<int>>(n, vector<int>(m,0));
        
        for(int i = 0; i < n; i++)
        {
            temp[i][0] = matrix[i][0];
            for(int j = 1; j < m; j++)
            {
                temp[i][j] = temp[i][j-1] + matrix[i][j];
            }
        }

        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++)
        {
            if(col1 > 0)
            {
                sum += temp[i][col2] - temp[i][col1 - 1];
            }
            else
            {
                sum += temp[i][col2];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */