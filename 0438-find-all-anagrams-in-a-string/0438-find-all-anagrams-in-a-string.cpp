class Solution {
public:
    void printMap(unordered_map<char, int>& mp){
	for(auto it: mp){
		cout << it.first << "->" << it.second << ' ';
	}
	cout << "" << endl;
}
    
    vector<int> findAnagrams(string s, string p) {
//         find p in s
//         window size = p.size();
//         using sliding window concept
        unordered_map<char, int> mp;
        for(auto x: p){
            mp[x]++;
        }
        
        int k = p.size();
        int i = 0, j = 0;
        int n = s.size();
        
        int count = mp.size();
        vector<int> res;
        while(j < n){
//             included j and hence add into the window
            // printMap(mp);
            // cout << count << endl;
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0){
        //                 no element
                    count--;
                }
            }
            
//             check window size
            if(j - i + 1 < k){
                j++;
            }else{
//                 window size matched
//                 check and remove from front
                if(count == 0){
                    res.push_back(i);
                }
                
//                 check from front
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]] == 1){
                        count++;
                    }
                }
                
                i++;
                j++;
            }
        }
        
        return res;
    }
};