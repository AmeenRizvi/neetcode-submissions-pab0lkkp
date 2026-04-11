class Solution {
    int R, C;
    vector<vector<bool>> seen;
    vector<int>shape;

    void explore(int r, int c, vector<vector<int>>& grid )
    {
        if(r >= 0 & r < R & c >= 0 && c < C && grid[r][c] == 1 && !seen[r][c])
        {
            seen[r][c] = true;
            shape.push_back(r*C + c);
            explore(r+1, c, grid);
            explore(r-1, c, grid);
            explore(r, c+1, grid);
            explore(r, c-1, grid);

        }
    }

    string canonical(vector<int> &shape)
    {
        string ans = "";
        int lift = R + C;
        int n = shape.size();
        vector<int> out(n), xs(n), ys(n);

        for(int c = 0; c < 8; c++)
        {
            for(int t = 0; t < n; t++)
            {
                int x = shape[t] / C;
                int y = shape[t] % C;

                xs[t] = c <= 1 ? x : c <= 3 ? -x : c <= 5 ? y : -y;
                ys[t] = c <= 3 ? (c%2 == 0 ? y : -y) : (c%2 == 0 ? x : -x);
            }

            int mx = *min_element(xs.begin(), xs.end());
            int my = *min_element(ys.begin(), ys.end());

            for(int j = 0; j < n; j++)
            {
                out[j] = (xs[j] - mx) * lift + (ys[j] - my);
            }
            sort(out.begin(), out.end());

            string candidate = "";
            for(int j = 0; j < n; j++)
            {
                if(j > 0) candidate += ",";
                candidate += to_string(out[j]);
            }
            if(candidate > ans)
            {
                ans = candidate;
            }
        }
        return ans;

    }
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();
        seen.assign(R, vector<bool>(C, false));
        set<string>shapes;

        for(int r = 0; r < R; r++)
        {
            for(int c = 0; c < C; c++)
            {
                shape.clear();
                explore(r, c, grid);
                if(!shape.empty()){
                    shapes.insert(canonical(shape));
                }
            }
        }
        return shapes.size();
        
    }
};
