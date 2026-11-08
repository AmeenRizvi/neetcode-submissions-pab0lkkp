class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {        
        int n = position.size();
        vector< pair<int,int>>temp;
        for(int i = 0; i < n; i++)
        {
            temp.push_back({position[i], speed[i]});
        }
        sort(temp.rbegin(), temp.rend());
        vector<double>time(n, 0);

        for(int i = 0; i < n; i++)
        {
            int d = target - temp[i].first;
            time[i] = (double)d/temp[i].second;
        }

        stack<double>st;
        st.push(time[0]);

        for(int i = 1; i < n; i++)
        {
            if(time[i] > st.top())
            {
                st.push(time[i]);
            }
        }

        return st.size();
    }
};
