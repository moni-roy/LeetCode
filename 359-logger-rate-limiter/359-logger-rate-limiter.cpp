class Logger {
public:
    unordered_map<string, int> mapTime;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(mapTime.find(message) != mapTime.end() && mapTime[message] > timestamp){
            return false;
        }
        mapTime[message] = timestamp + 10;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */