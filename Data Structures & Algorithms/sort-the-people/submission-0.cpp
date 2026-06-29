struct CompareHeights {
        bool operator()(pair<string,int>&a, pair<string,int>&b)
        {
            return a.second > b.second;        
        }
    };
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string,int>> data;

        for(int i = 0; i < names.size(); i++)
        {
            data.push_back({ names[i], heights[i] });
        }

        sort(data.begin(), data.end(), CompareHeights() );

        vector<string>ans;
        for(auto &[name, height] : data)
        {
            ans.push_back(name);
        }
        return ans;

        
    }
};