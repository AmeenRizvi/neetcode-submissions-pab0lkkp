class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>unique;

        for(string &e : emails)
        {
            string mail = "";
            auto atPos = e.find('@');
            string local = e.substr(0, atPos);
            string domain = e.substr(atPos);

            for(char c : local)
            {
                if(c == '.') continue;
                if(c == '+') break;
                mail += c;
            }
            mail += domain;
            unique.insert(mail);
            
        }
        return unique.size();

        
    }
};