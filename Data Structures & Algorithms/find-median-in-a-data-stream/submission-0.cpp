class MedianFinder {
    vector<int>nums;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        nums.push_back(num);
    }
    
    double findMedian() {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n%2 == 1)
            return (double)nums[n/2];
        else
        {
            int num1 = nums[n/2-1];
            int num2 = nums[n/2];

            return (double)(num1+num2)/2;
        }
        
    }
};
