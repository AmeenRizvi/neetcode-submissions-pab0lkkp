class Compare{
    bool operator()(vector<int>&a, vector<int>&b)
    {
        if(a[1] == b[1])
        {
            return a[0] > b[0];
        }  
        return a[1] < b[1];
    }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>freq;

        for(int num : nums)
        {
            freq[num]++;
        }
        vector<pair<int,int>>temp;

        for(auto &p : freq)
        {
            temp.push_back({p.first, p.second});
        }

        sort(temp.begin(), temp.end(), [](auto&a, auto&b){
            if(a.second != b.second) return a.second < b.second;
            return a.first > b.first;
        });

        vector<int>ans;
        for(auto &p : temp)
        {
            for(int i = 0; i < p.second; i++)
            {
                ans.push_back(p.first);
            }
        }
        return ans;
        
    }
};