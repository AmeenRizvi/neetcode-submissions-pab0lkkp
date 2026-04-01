class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int>maxHeap;

        for(int stone : stones)
        {
            maxHeap.push(stone);
        }

        while(maxHeap.size() > 1)
        {
                int top1 = maxHeap.top();
            maxHeap.pop();
            int top2 = maxHeap.top();
            maxHeap.pop();

            int cur = top1 - top2;
            if(cur > 0)
            {
                maxHeap.push(cur);
            }
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
        
    }
};
