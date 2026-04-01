class KthLargest {
    vector<int>temp;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        temp = nums;
        K = k;
    }
    
    int add(int val) {
        temp.push_back(val);
        sort(temp.begin(), temp.end());
        int n = temp.size();
        return temp[n-K];
    }
};
