class RandomizedSet {
    unordered_map<int,int>mp;
    vector<int>arr;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val) )
        {
            return false;
        }
        int idx = arr.size();
        mp[val] = idx;
        arr.push_back(val);
        return true;
        
    }
    
    bool remove(int val) {
        if(mp.count(val) == 0)
        {
            return false;
        }
        int idx = mp[val];
        int last = arr.back();
        arr[idx] = last;
        mp[last] = idx;
        arr.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = arr.size();
        
        int num = rand()%n ;

        return arr[num];


    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */