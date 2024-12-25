class RandomizedSet {
    unordered_map<int, int> valToIndex;
    vector<int> values;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (valToIndex.count(val)) return false;

        valToIndex[val] = values.size(); // this is the new index
        values.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!valToIndex.count(val)) return false;
        // we are moving the value to be removed to the back of the vector to be O(1) removal cost
        int idxToRemove = valToIndex[val];

        values[idxToRemove] = values.back();
        valToIndex[values.back()] = idxToRemove;

        values.pop_back();
        valToIndex.erase(val);

        return true;
    }
    
    int getRandom() {
        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */