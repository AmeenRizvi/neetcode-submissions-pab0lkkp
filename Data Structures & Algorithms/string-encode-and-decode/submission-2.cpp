class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty())
            return "";
        
        vector<int>sizes;
        string res = "";
        for(string &str : strs)
        {
            sizes.push_back(str.size());
        }

        for(int sz : sizes)
        {
            res += to_string(sz) + ',';
        }
        res += '#';

        for(string &str : strs)
        {
            res += str;
        }
        return res;
    }

    vector<string> decode(string s) {
        if(s.empty())
            return {};
        
        vector<int>sizes;
        vector<string>res;
        int i = 0;

        while(s[i] != '#')
        {
            string cur = "";
            while(s[i] != ',')
            {
                cur += s[i];
                i++;
            }
            sizes.push_back(stoi(cur));
            i++;
        }
        i++;

        for(int sz : sizes)
        {
            res.push_back(s.substr(i, sz));
            i += sz;
        }
        return res;

    }
};
