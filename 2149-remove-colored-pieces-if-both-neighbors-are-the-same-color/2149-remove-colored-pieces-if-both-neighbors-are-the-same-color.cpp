class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0, bob = 0;

        int n = colors.size();
        int sz = 3; // the window should be of size 3

        int i = 0, j = 0;

        unordered_map<char, int> mp;

        while(j < n){
            mp[colors[j]]++;
            if(j - i + 1 < sz){
                // window size not matched
                // so continue
                j++;
            }
            else{
                // window size is matching
                // so move i++ and j++
                if(mp.size() == 1){
                    // find whether it is A or not
                    auto it = mp.begin();
                    if(it->first == 'A'){
                        alice++;
                    }else{
                        bob++;
                    }
                }else{
                    // the size is 2
                    // do nothing
                }
                // remove back and move one
                char last = colors[i];
                mp[last]--;
                if(mp[last] == 0){
                    mp.erase(last);
                }

                // move i and j
                i++;
                j++;
            }
        }

        cout << alice << " " << bob << endl;

        // alice and bob are populated now
        while(alice != 0 && bob != 0){
            alice--;
            bob--;
        }

        if(alice == 0){
            // bob wins
            return false;
        }
        else {
            // alice wins
            return true;
        }
        
        return 0;
    }
};