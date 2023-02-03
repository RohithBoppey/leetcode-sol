class Solution {
public:
    void print(vector<string> s){
        for(auto x: s){
            cout << x << endl;
        }
        cout << endl;
    }
    
    string convert(string s, int rows) {
        int n = s.length();
        if(rows == 1){
            return s;
        }
        vector<string> v(rows, "");
        
        int curr = 0, flag = 0;
        for(int i = 0; i < n; i++){
            v[curr] += s[i];
            if(flag == 0){
                curr++;
            }else{
                curr--;   
            }
            if(curr >= rows){
                curr = rows - 2;
                flag = 1;
            }else if(curr < 0){
                curr = 1;
                flag = 0;
            }
            // print(v);
        }
        
        string res;
        for(auto x: v){
            res += x;
        }
        
        return res;
    }
};