class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowSize = n -k;

        if(windowSize == 0)
        {
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        }

        int total = 0;
        int minWindowSum = INT_MAX;
        int curSum = 0;
        
        for(int i = 0; i < n; i++)
        {
            total += cardPoints[i];
            curSum += cardPoints[i];

            if(i >= windowSize - 1)
            {
                minWindowSum = min(minWindowSum, curSum);
                curSum -= cardPoints[i - windowSize + 1];
            }
        }
        return total - minWindowSum;
        
    }
};