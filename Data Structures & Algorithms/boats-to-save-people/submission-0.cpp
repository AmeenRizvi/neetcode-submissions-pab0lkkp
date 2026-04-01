class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int l = 0, r = n-1;
        int boat = 0;

        while(l <= r)
        {
            boat++;
            int remain = limit - people[r];
            r--;
            if(l <= r && remain >= people[l])
            {
                l++;
            }
        }
        return boat;
        
    }
};