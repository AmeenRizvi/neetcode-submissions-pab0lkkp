class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        unordered_map<string, int>freq;

        for(auto &str : arr)
        {
            freq[str]++;
        }

        int count = 0;
        for(auto &str : arr)
        {
            if(freq[str] == 1)
            {
                count++;
                if(count == k)
                {
                    return str;
                }
            }
        }
        return "";
        
    }
};