class UndergroundSystem {
private:
    unordered_map<string, pair<int, int>> checkOutMap;
    unordered_map<int, pair<string, int>> checkInMap;
    
public:
    UndergroundSystem() {

    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string outStation = checkInMap[id].first + " $ " + stationName;
        checkOutMap[outStation].first += t - checkInMap[id].second;
        checkOutMap[outStation].second += 1;
    }
    double getAverageTime(string startStation, string endStation) {
        string outStation = startStation + " $ " + endStation;
        return (checkOutMap[outStation].first + 0.0) / checkOutMap[outStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */