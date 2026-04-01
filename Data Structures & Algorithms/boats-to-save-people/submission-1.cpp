class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int m = *max_element(people.begin(), people.end());
        vector<int>count(m+1, 0);

        for(int p : people)
        {
            count[p]++;
        }

        int idx = 0, i = 1;
        while(idx < people.size())
        {
            while(count[i] == 0)
            {
                i++;
            }
            people[idx] = i;
            idx++;
            count[i]--;
        }

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