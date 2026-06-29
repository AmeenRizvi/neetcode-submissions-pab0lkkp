class Logger {
    unordered_map<string,int>mp;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        
        if( mp.count(message) )
        {
            if(timestamp - mp[message] >= 10)
            {
                mp[message] = timestamp;
                return true;
            }
            return false;
        }
        else
        {
            mp[message] = timestamp;
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
