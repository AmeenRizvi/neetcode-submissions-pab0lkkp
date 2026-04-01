class Solution {
    int findDist(vector<int>&worker, vector<int>&bike)
    {
        return abs(worker[0]-bike[0]) + abs(worker[1]-bike[1]);
    }
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<tuple<int,int,int>>allTriplets;

        for(int worker = 0; worker < workers.size() ; worker++)
        {
            for(int bike = 0; bike < bikes.size(); bike++)
            {
                int dist = findDist(workers[worker], bikes[bike]);
                allTriplets.push_back({dist, worker, bike});
            }
        }

        sort(allTriplets.begin(), allTriplets.end());

        vector<int>bikeStatus(bikes.size(), false);

        vector<int>workerStatus(workers.size(), -1);

        int pairCount = 0;

        for(auto[dist, worker, bike] : allTriplets)
        {
            if(workerStatus[worker] == -1 && !bikeStatus[bike])
            {
                bikeStatus[bike] = true;
                workerStatus[worker] = bike;
                pairCount++;
            }
            if(pairCount == workers.size())
                return workerStatus;
        }

        return workerStatus;

        
    }
};
