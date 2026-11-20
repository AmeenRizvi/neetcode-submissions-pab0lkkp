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
        while(idx < people.size() )
        {
            while(count[i] == 0)
            {
                i++;
            }
            people[idx] = i;
            idx++;
            count[i]--;
        }

        int l = 0, r = people.size()-1;
        int ans = 0;

        while(l <= r)
        {
            if(people[l] + people[r] <= limit)
            {
                l++;
            }
            r--;
            ans++;
        }
        return ans;


        
    }
};