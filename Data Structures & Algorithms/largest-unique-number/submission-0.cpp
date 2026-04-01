class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num : nums)
        {
            mp[num]++;
        }

        int largest = -1;
        for(auto &p : mp)
        {
            if(p.second == 1 && p.first > largest)
            {
                largest = p.first;
            }
        }
        return largest;
        
    }
};
