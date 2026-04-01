class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {

        map<int, priority_queue<int,vector<int>, greater<int>>> allScores;

        for(auto &item : items)
        {
            int id = item[0];
            int score = item[1];

            allScores[id].push(score);
            if(allScores[id].size() > 5)
            {
                allScores[id].pop();
            } 
        }

        vector<vector<int>>ans;
        for(auto &[id, top] : allScores)
        {
            int total = 0;

            for(int i = 0; i < 5; i++)
            {
                total += top.top();
                top.pop();
            }
            ans.push_back({id, total/5});
        }
        return ans;


        
        
    }
};
