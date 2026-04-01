class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int d = (arr.back() - arr.front() )/n;
        int l = 0, r = n-1;

        while(l < r)
        {
            int mid = (l+r)/2;

            if(arr[mid] == arr.front() + mid*d)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }

        }
        return arr.front() + d*l ;
    }
};
