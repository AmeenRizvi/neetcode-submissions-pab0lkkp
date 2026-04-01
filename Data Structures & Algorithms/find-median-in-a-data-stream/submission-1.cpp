class MedianFinder {
    priority_queue<int, vector<int>, less<int>> p;
    priority_queue<int, vector<int>, greater<int>> q; 
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        p.push(num);

        if(!q.empty() && p.top()>q.top())
        {
            q.push(p.top());
            p.pop();
        }

        if(p.size() > q.size()+1)
        {
            q.push(p.top());
            p.pop();
        }

        if(q.size() > p.size() + 1)
        {
            p.push(q.top());
            q.pop();
        }
        
    }
    
    double findMedian() {
        if(p.size() == q.size())
        {
            return (p.top() + q.top() )/2.0;
        }
        else if(p.size() > q.size())
            return p.top();
        else
            return q.top();
        
    }
};
