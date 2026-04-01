class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;

        for(int num = 0; num <= n; num++)
        {
            int temp = num, count = 0;
            while(temp != 0)
            {
                temp = temp&(temp-1);
                count++;
            }
            ans.push_back(count);
        }
        return ans;
        
    }
};
