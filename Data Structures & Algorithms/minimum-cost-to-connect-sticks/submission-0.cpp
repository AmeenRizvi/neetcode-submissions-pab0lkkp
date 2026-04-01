class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>>minHeap;

        for(int stick : sticks)
        {
            minHeap.push(stick);
        }

        int ans = 0;
        while(minHeap.size() > 1)
        {
            int min1 = minHeap.top();
            minHeap.pop();

            int min2 = minHeap.top();
            minHeap.pop();

            ans += min1 + min2;
            minHeap.push(min1 + min2);
        }
        return ans;
    }
};
