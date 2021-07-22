class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, map<int, string>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].insert({ timestamp, value });
    }
    
    string get(string key, int timestamp) {
        if (!store.count(key))
            return "";
        auto it = store[key].upper_bound(timestamp);
        if (it == store[key].begin())
            return "";
        it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */