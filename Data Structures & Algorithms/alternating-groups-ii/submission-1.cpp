class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0;
        int streak = 1;
        for(int i = 1; i < n+k-1; i++)
        {
            if(colors[i%n] != colors[(i-1)%n])
            {
                streak++;
            }
            else
            {
                streak = 1;
            }

            if(streak >= k)
            {
                ans++;
            }
        }
        return ans;

    }
};
