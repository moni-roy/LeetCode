class MyHashSet {
private:
    vector<bool> hash_table;
    int hash_size;
public:
    MyHashSet() {
        hash_size = 1000001;
        // initialize hash table with false
        hash_table.resize(hash_size, false);

    }
    
    void add(int key) {
        hash_table[key] = true;   
    }
    
    void remove(int key) {
        hash_table[key] = false;
    }
    
    bool contains(int key) {
        return hash_table[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */