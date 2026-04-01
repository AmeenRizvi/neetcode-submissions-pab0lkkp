class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int,int>mp;

        for(int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        
        int ans = 0;
        for(auto &p : mp)
        {
            int ele = p.first;
            if(mp.find(ele+1) != mp.end())
            {
                ans+= p.second;
            }
        }
        return ans;
        
    }
};
