class UndergroundSystem {
public:
    
    // contains 10 -> {Leyton, startTime}
    unordered_map<int, pair<string,int>> checkInMap; 
    
    // contains Leyton_Station -> {amount, count}
    unordered_map<string, pair<double, int>> route; 
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        // delete from checkIn and add to route
        pair<string,int> firstStop = checkInMap[id];
        checkInMap.erase(id);
        
        // add to route
        string routeName = firstStop.first + '_' + stationName;
        route[routeName].first += t - firstStop.second;
        route[routeName].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeName = startStation + '_' + endStation;
        return route[routeName].first / route[routeName].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */