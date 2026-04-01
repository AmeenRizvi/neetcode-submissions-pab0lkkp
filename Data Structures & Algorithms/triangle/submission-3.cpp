class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size(), cols = triangle[rows-1].size();


        for(int j = rows-2; j >= 0; j--)
        {
            for(int i = triangle[j].size()-1; i >= 0; i--)
            {
                triangle[j][i] = min(triangle[j+1][i], triangle[j+1][i+1]) + triangle[j][i];
            }
        }
        return triangle[0][0];
        
    }
};