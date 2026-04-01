class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size(), cols = triangle[rows-1].size();
        vector<int>row(cols, 0);
        vector<int>nextRow(cols, 0);

        for(int i = cols-1; i >= 0; i--)
        {
            nextRow[i] = triangle[rows-1][i];
        }

        for(int j = rows-2; j >= 0; j--)
        {
            for(int i = cols-1; i >= 0; i--)
            {
                row[i] = min(nextRow[i], nextRow[i+1]) + triangle[j][i];
            }
            swap(row, nextRow);
        }
        return nextRow[0];
        
    }
};