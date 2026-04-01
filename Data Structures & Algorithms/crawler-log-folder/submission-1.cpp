class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for(auto &str : logs)
        {
            if(str == "./")
                continue;
            else if(str == "../")
            {
                count = max(count-1, 0);
            }
            else
            {
                count++;
            }
        }

        return count;
        
    }
};