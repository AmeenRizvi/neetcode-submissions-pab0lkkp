class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        map<int, vector<int>>mp;

        for(auto &ele : arr)
        {
            int diff = abs(ele-x);
            mp[diff].push_back(ele);
        }

        vector<int>ans;
        for(auto &p:mp)
        {
            for(auto &num:p.second)
            {
                ans.push_back(num);
                if(ans.size() == k)
                {
                    sort(ans.begin(), ans.end());
                    return ans;
                }
            }
        }
        return {};
        
    }
};