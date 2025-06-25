class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";

        // now it is present in the map
        // using binary search, find the correct one
        auto &v = mp[key];
        
        int low = 0, high = v.size() - 1, mid; 
        string res;

        while(low <= high){
            mid = low + (high - low) / 2; 
            auto &x = v[mid];

            if(x.first == timestamp){
                // given timestamp is found
                return x.second; 
            }else if(x.first > timestamp){
                // pakka should not take
                high = mid - 1;
            }else{
                // this can be the value if the exact value is not present
                // this gets incremented each time
                res = x.second;
                low = mid + 1;
            }
        }

        return res;

    }
};
