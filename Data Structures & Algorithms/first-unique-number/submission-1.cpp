class FirstUnique {
    queue<int>q;
    unordered_map<int,int>mp;
public:
    FirstUnique(vector<int>& nums) {
        for(int num : nums)
        {
            this->add(num);
        }
    }
    
    int showFirstUnique() {
        while(!q.empty() && !mp[q.front()])
        {
            q.pop();
        }

        if(!q.empty()){
            return q.front();
        }

        return -1;
        
    }
    
    void add(int value) {
        if(mp.find(value) == mp.end())
        {
            q.push(value);
            mp[value] = true;
        }
        else
        {
            mp[value] = false;
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
