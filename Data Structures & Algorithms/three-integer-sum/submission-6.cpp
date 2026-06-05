class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if( nums.size() < 3 ) return {};

    	int n = nums.size();
	    sort(nums.begin(), nums.end() );
        vector<vector<int>>ans;	

    	for(int i = 0; i < n; i++)
	    {
		    if(i > 0 && nums[i] == nums[i-1] )
		    {
			    continue;
            }
    		int l = i+1, r = n-1, target =  -nums[i];
	    	while(l < r)
		    {
			    int sum = nums[l] + nums[r];
    			if( sum == target )
	    		{
		    		ans.push_back( { nums[i], nums[l], nums[r]  } );
			    	l++;
				    r--;
				    while(l > 0 && l < r && nums[l] == nums[l-1])
                        l++;
                    while(r < n-1 &&  l < r && nums[r] == nums[r+1]) 
					    r--;
            }
            else if( sum < target )
            {
    	        l++;
            }
            else
            {
	        r--;
            }
        }
    }   
    return ans;    
    }
};
