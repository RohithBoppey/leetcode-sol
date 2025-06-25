- since given that timestamps are pushed in the sorted order only, we can write a data structure like this: `key -> {timestamp, value}` i.e. `string -> vector<pair<int, string>>`
- and by doing this, for the setting of key, it is just appending to the end
- for getting, on the array, we can perform the binary search like: `foo => [ {1, key} , {2, key} ]` and so on
- based on the length, do binary search with boundary conditions properly. 

```c++
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

```
