class Solution {
    int cntOne(int n)
    {
        int cnt = 0;
        while(n != 0)
        {
            cnt++;
            n = n&(n-1);
        }
        return cnt;
    }
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        ans.push_back(0);

        for(int i = 1; i <= n; i++)
        {
            int tmp = cntOne(i);
            ans.push_back(tmp);
        }
        return ans;
        
    }
};
