class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(table.find(val) != table.end())
			return false;
		vec.push_back(val);
		table.insert(make_pair(val, vec.size() - 1));
		return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(table.find(val) == table.end())
			return false;
		int num(vec.back());
		table[num] = table[val];
		vec[table[num]] = num;
		vec.pop_back();
		table.erase(val);
		return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vec[rand() % vec.size()];
    }
private:
	vector<int> vec;
	unordered_map<int, int> table;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */