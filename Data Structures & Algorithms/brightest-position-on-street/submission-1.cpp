class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        map<int,int>diff;
        for(int i = 0; i < lights.size(); i++)
        {
            int st = lights[i][0] - lights[i][1];
            int en = lights[i][0] + lights[i][1];

            diff[st]++;
            diff[en+1]--;
        }
        int ans = -1, maxLight = 0, curr = 0;

        for(auto &[key, val] : diff)
        {
            curr += val;
            if(curr > maxLight)
            {
                maxLight = curr;
                ans = key;
            }
        }
        return ans;
    }
};
