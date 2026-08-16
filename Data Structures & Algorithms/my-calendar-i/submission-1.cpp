class MyCalendar {
    vector<vector<int>>arr;
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        int n = arr.size();

        for(int i = 0; i < n; i++)
        {
            if( max(arr[i][0], startTime ) < 
            min(arr[i][1], endTime ) )
            {
                return false;
            }
        }

        arr.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */