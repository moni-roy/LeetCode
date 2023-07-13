class TimeMap {
public:
    unordered_map<string, set<pair<int, string>>> mp;
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
       mp[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = mp[key].lower_bound({timestamp + 1, ""});
        if (it == mp[key].begin()) return "";
        return prev(it)->second;
    }
};
