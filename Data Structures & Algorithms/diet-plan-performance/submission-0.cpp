class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n = calories.size();
        int score = 0, t = 0;

        for(int i = 0; i < k; i++)
        {
            t += calories[i];
        }
        if(t < lower)
        {
            score -= 1;
        }
        else if(t > upper)
        {
            score += 1;
        }

        for(int i = k; i < n; i++)
        {
            t -= calories[i-k];
            t += calories[i];

            if(t < lower)
            {
                score -= 1;
            }
            else if(t > upper)
            {
                score += 1;
            }
        }

        return score;
    }
};
