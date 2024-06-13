Asked in `Amaon` & `Tesla`      
My own algo fails for the test case `aabbcc`:   
      
![WhatsApp Image 2023-08-23 at 16 13 26](https://user-images.githubusercontent.com/73538974/262643828-c66a60a8-ce29-4fc2-afbd-c6eaa34632a4.jpg)
![WhatsApp Image 2023-08-23 at 16 13 27](https://user-images.githubusercontent.com/73538974/262643858-79be093e-3b4c-4afb-8273-1d147b1e8d65.jpg)

```
class Solution {
public:
    int stringToInt(const std::string& str) {
        int result = 0;
        size_t i = 0;
        // Convert characters to integer value
        while (i < str.length()) {
            if (str[i] >= '0' && str[i] <= '9') {
                result = result * 10 + (str[i] - '0');
                i++;
            } else {
                // Non-numeric character encountered
                break;
            }
        }
        return result;
    }

    string reorganizeString(string s) {
        int n = s.size();
        if(n == 1){
            // single letter
            return s;
        }
        
        vector<int> freq(26, 0); // [a-z]
        vector<pair<int, char>> toSort;
        vector<char> tr(n, '-');
        
        // populating freq array
        for(int i = 0; i < n; i++){
            freq[s[i] - 'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            // pushing in num_char -> 4_b format
            if(freq[i] != 0){
                toSort.push_back({freq[i], (char)('a' + i)});
            }
        }
        
        // should sort in descending order
        sort(toSort.begin(), toSort.end());
        reverse(toSort.begin(), toSort.end());
        
        // printPairVector(toSort);
        
        // start filling from the start
        string t;
        char ch;
        int f, sz;
        for(int i = 0; i < toSort.size(); i++){
            ch = toSort[i].second;
            f = toSort[i].first;           
            if(
                (n % 2 == 0 && f > n / 2) || 
                (n % 2 == 1 && f > (n / 2) + 1)){
                // not possible
                return "";
            }
            // finding from where should we start
            int ind = 0;
            for(; ind < n; ind++){
                if(tr[ind] == '-'){
                    // should start
                    break;
                }
            }
            while(ind < n && f > 0){
                tr[ind] = ch;
                ind += 2;
                f--;
            }
        }
        
        // printVector(tr);
        // converting the vector<char> to string
        
        string result = "";
        for(int i = 0; i < n; i++){
            result += tr[i];
        }
        return result;
    }
};
```
      
The problem with this code is that, we are not continuing the index, if we keep filling from 0 and so on, then for the last 2 there is a small thing.     
Hence, we need to keep filling from the same index
    
 Along with that, some corrections:
 - We can do it with freq array.
 - We can return null string right when populating freq.
 - If we were to fill, start with max ones, coz in the worst case, index >= n happens just once, revert back to 1 and then fill in between.
      
```
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        
        // using this to mark max char & its freq 
        int mxFreq = 0; 
        char mxChar = 'a';
        for(int i = 0; i < n; i++){
            freq[s[i] - 'a']++;
            if(mxFreq < freq[s[i] - 'a']){
                mxFreq = freq[s[i] - 'a'];
                mxChar = s[i];
            }
            if(freq[s[i] - 'a'] > (n + 1) / 2){
                // cannot be possible
                return "";
            }
        }
        
        // now frequency array is populated and we know the max occuring element
        // deal with that first -> fill that first
        string result = s;
        int start = 0;
        
        while(mxFreq > 0){
            result[start] = mxChar;
            start += 2;
            mxFreq--;
            freq[mxChar - 'a']--;
        }
        
        // now fill in the rest
        for(int i = 0; i < 26; i++){
            while(freq[i] > 0){
                // should fill
                if(start >= n){
                    // max it will be repeated just once
                    start = 1;
                }
                result[start] = (char)(i + 'a');
                start += 2;
                freq[i]--;
            }
        }
        
        return result;
    }
};
```

DRY RUN FOR THIS APPROACH:    
![image](https://user-images.githubusercontent.com/73538974/262642853-199de353-e27e-473c-a181-c86261706be9.png)
![image](https://user-images.githubusercontent.com/73538974/262642879-985af089-a4d0-4d36-a6aa-76bc7f0629a9.png)
![image](https://user-images.githubusercontent.com/73538974/262642890-2da08b89-de27-4f6b-8ec7-e4ca69fd0908.png)
![image](https://user-images.githubusercontent.com/73538974/262642923-bcb98b06-b1c7-4be1-a2ac-4ad6fcf07434.png)
![image](https://user-images.githubusercontent.com/73538974/262642957-7a684f9d-1252-4150-9a3d-4769eaca98e9.png)
![image](https://user-images.githubusercontent.com/73538974/262642977-ea67fc3a-92db-4dab-935c-11ad94770451.png)
    
        
APPROACH 2: (USING MAX HEAP -> INSTEAD OF SORTING, THIS IS BETTER)      
      
DRY RUN:    
      
![image](https://user-images.githubusercontent.com/73538974/262643080-1767e625-2550-4741-b763-a12e423f8d24.png)
![image](https://user-images.githubusercontent.com/73538974/262643109-9fba61d9-cde5-448a-9cd4-3ce888e0bc94.png)
![image](https://user-images.githubusercontent.com/73538974/262643348-39e7733d-3e90-4c60-baf7-8bf238dd02d9.png)
![image](https://user-images.githubusercontent.com/73538974/262643373-922bd7bc-ced0-42c5-ba1c-44c28d1cb0c2.png)
![image](https://user-images.githubusercontent.com/73538974/262643412-b6c9f8c6-dc36-48c3-9e52-5fa166122234.png)
![image](https://user-images.githubusercontent.com/73538974/262643451-52f3ed94-4559-4501-9413-c035573c4b4f.png)
      
CODE:       
```
class Solution {
public:
    typedef pair<int, char> P;
    
    string reorganizeString(string s) {
        // USING PRIORITY QUEUE SOLUTION
        int n = s.size();
        
        // populating freq array
        vector<int> freq(26, 0);
        for(auto &ch: s){
            freq[ch - 'a']++;
            if(freq[ch - 'a'] > (n + 1) / 2){
                // not possible
                return "";
            }
        }
        
        // pushing the valid ones into priority queue
        priority_queue<P, vector<P>> pq;
        
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                // that means it exists
                pq.push({freq[i], (char)('a' + i)});
            }
        }
        
        // processing the pq
        string result = "";
        while(pq.size() >= 2){
            // doing this twice to ensure not repeating
            P p1 = pq.top();
            pq.pop();
            
            P p2 = pq.top();
            pq.pop();
            
            result += p1.second;
            result += p2.second;
            
            p1.first--;
            p2.first--;
            
            if(p1.first > 0){
                pq.push(p1);
            }
            
            if(p2.first > 0){
                pq.push(p2);
            }
            
        }
        
        // finally if there is some element left in pq, we can safely add
        if(!pq.empty()){
            P p1 = pq.top();
            pq.pop();
            
            result += p1.second;
        }
        
        return result;
    }
};
```

​
