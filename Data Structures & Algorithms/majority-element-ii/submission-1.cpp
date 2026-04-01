class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int nums1 = -1, nums2 = -1, cnt1 = 0, cnt2 = 0;

        for(int num : nums)
        {
            if(num == nums1)
            {
                cnt1++;
            }
            else if(num == nums2)
            {
                cnt2++;
            }
            else if(cnt1 == 0)
            {
                nums1 = num;
                cnt1 = 1;
            }
            else if(cnt2 == 0)
            {
                nums2 = num;
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for(int num : nums)
        {
            if(num == nums1) cnt1++;
            else if(num == nums2) cnt2++;
        }

        vector<int>ans;
        if(cnt1 > n/3) ans.push_back(nums1);
        if(cnt2 > n/3) ans.push_back(nums2);

        return ans;
    }
};