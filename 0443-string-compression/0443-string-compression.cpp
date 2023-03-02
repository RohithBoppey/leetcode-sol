class Solution {
public:
    int compress(vector<char>& chars) {
        /*
            The idea is to maintain 2 pointers
            one to iterate and second to change
        */
        
        int n = chars.size();
        if(n == 1){
            return 1;
        }
        
        int i = 0, j = 0;
        
        while(i < n){
            int count = 1;  
            while(i < n - 1 && chars[i] == chars[i+1]){
//                 same character, increment the iterator
                i++;
                count++;
            }
            
//             copy the character to the updating index
            chars[j] = chars[i];
            j++;
            i++;
            
//             from j, we need to give the count
            if(count > 1){
                string s = to_string(count);

                for(auto ch: s){
                    chars[j] = ch;
                    j++;
                }
            }
            
//             now j is pointing to the next required updated index
//             we need to update count again
                
        }
         
//         now j indirectly points to the size of the updated size
//         so can return
        
        return j;
    }
};



