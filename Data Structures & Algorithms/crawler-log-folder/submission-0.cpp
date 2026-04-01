class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>st;
        int count = 0;
        for(auto &str : logs)
        {
            if(str == "./")
                continue;
            else if(str == "../")
            {
                if(!st.empty())
                {
                    st.pop();
                    count--;
                }
            }
            else
            {
                st.push(str);
                count++;
            }
        }

        return count;
        
    }
};