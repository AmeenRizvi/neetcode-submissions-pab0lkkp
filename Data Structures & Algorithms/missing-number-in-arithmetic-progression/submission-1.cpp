class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int a = arr.front();
        int d = (arr.back() - arr.front() )/n;

        for(int &val : arr)
        {
            if(val != a) return a;

            a += d;
        }
        return a;
    }
};
