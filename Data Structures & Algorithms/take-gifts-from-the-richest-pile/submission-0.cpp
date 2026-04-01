class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;

        for(int gift : gifts)
        {
            pq.push(gift);
        }

        for(int i = 0; i < k; i++)
        {
            int g = pq.top();
            pq.pop();
            int leftG = sqrt(g);
            pq.push(leftG);
        }

        long long ans = 0;

        while(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};