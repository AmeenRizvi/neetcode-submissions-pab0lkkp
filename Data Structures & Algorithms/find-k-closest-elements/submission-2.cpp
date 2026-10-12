class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> >pq;

        for(auto &ele : arr)
        {
            int diff = abs(ele-x);
            pq.push({diff, ele});
        }

        vector<int>ans;
        for(int i = 0; i < k; i++)
        {
            vector<int>top = pq.top();
            pq.pop();

            ans.push_back(top[1]);
        }
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};