class BrowserHistory {
public:
    vector<string> history;
    vector<string>::iterator current;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        current = history.begin();
    }
    
    void visit(string url) {   
        history.erase(current + 1, history.end());
        history.push_back(url);
        current = history.end() - 1;

    }
    
    string back(int steps) {
        while (steps-- && current != history.begin()) {
            --current;
        }
        return *current;
    }
    
    string forward(int steps) {
        while (steps-- && current != history.end() - 1) {
            ++current;
        }
        return *current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */