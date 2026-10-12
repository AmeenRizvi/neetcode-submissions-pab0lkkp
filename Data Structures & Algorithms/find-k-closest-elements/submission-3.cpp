class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0, r = n -1;

        while(r-l >= k)
        {
            if(abs(x-arr[l]) <= abs(x-arr[r]))
            {
                r--;
            }
            else
            {
                l++;
            }
        }

        return vector<int>(arr.begin()+l, arr.begin()+r+1);
        
    }
};