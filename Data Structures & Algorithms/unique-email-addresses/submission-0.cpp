class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>s;

        for(string &str : emails)
        {
            int i = 0, n = str.size();
            string mail = "";
            while(i < n)
            {
                if(str[i] == '.')
                {
                    i++;
                    continue;
                }
                if(str[i] == '+')
                {
                    while(str[i] != '@')
                    {
                        i++;
                    }
                }
                if(str[i] == '@')
                {
                    while(i < n)
                    {
                        mail += str[i];
                        i++;
                    }
                }
                mail += str[i];
                i++;
            }
            s.insert(mail);
        }
        return s.size();
        
    }
};