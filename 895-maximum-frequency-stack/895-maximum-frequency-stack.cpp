class FreqStack {
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> freq_stacks;
    int max_freq;
public:
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        if (freq[val] > max_freq) {
            max_freq = freq[val];
        }
        freq_stacks[freq[val]].push(val);
    }
    
    int pop() {
        int val = freq_stacks[max_freq].top();
        freq_stacks[max_freq].pop();
        freq[val]--;
        if(freq_stacks[max_freq].empty()) {
            max_freq--;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */