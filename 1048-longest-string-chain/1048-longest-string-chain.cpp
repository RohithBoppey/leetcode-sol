    
bool cmp(string &lhs, string &rhs) {
    return lhs.length() < rhs.length();
}

class Solution {
public:
    
    vector<int> len;
    int n;
    
    bool check(string& s1, string &s2){
        int n = s2.length();

        string s = "";

        bool flag = false;;
        
        for(int i = 0; i < n; i++){
            if(i == 0){
                s = s2.substr(1, n);
            }
            else if(i > 0 && i < n - 1){
                s = s2.substr(0, i) + s2.substr(i + 1, n);
            }
            else{
                s = s2.substr(0, n - 1);
            }
            
            if(s == s1) {
                flag = true;
                break;
            }
        }
        
        return flag;
    }
    
    int solve(vector<string>& words, int start, int& mx){
        if(start >= n){
            return 0;
        }    
        
        if(len[start] != -1){
            // already calc
            return len[start];
        }
        
        int l = 1;
        // now process
        for(int i = start + 1; i < n; i++){
            if(words[i].length() > words[start].length() + 1){
                // we need not take it
                break;
            }
            
            if(words[i].length() == words[start].length() + 1){
                // we must take it
                // and check if words[start] is pred
                if(check(words[start], words[i]) == true){
                    l = max(l, 1 + solve(words, i, mx));
                }
            }
        }
        
        mx = max(mx, l);
        return len[start] = l;
        
    }
    
    void print(vector<int>& v){
        for(auto x: v){
            cout << x << " ";
        }
        cout << endl;
    }
    
    
    int longestStrChain(vector<string>& words) {
        n = words.size();
        
        if(n == 1){
            // number of words are 1, so max is also 1
            return 1;
        }
        
        int mx = 0;
        
        // sort explicitly based on length
        sort(begin(words), end(words), cmp);
        
        len.resize(n, -1);
        len[n - 1] = 1;
        
        for(int i = 0; i < n; i++){
            if(len[i] == -1){
                // not calc
                solve(words, i, mx);    
            }
        }
        
        // print(len);
        
        return mx;
        
    }
};