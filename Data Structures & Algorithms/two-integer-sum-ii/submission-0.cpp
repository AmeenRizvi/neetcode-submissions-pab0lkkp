class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if( numbers.empty() || numbers.size() == 1 ) return {};
	
    	int n = numbers.size();
	    int left = 0, right = n-1;
	
	    while(left < right)
	    {
		    long long sum = numbers[left] + numbers[right];
    		if(sum == target)
	    	{
		    	return {left+1, right+1};
            }
            else if( sum > target )
            {
	            right--;
            }
            else
            {
	            left++;
            }
        }
        return {};
    }
};
