class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 0;

        sort(people.begin(), people.end());
        int n = people.size(); 

        int low = 0, high = n - 1;
        
        while(low < high){
            if(people[low] + people[high] > limit){
                // meaning only send the heavy people in a single boat
            }else{
                // can send 2 people in this boat
                low++;
            }
            boats++;
            high--;
        }

        if(low == high){
            // meaning a single person got left
            boats++;
        }

        return boats; 
    }
};