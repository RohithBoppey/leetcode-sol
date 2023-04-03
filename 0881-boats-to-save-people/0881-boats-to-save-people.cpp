class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
//         using 2 pointer
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int count = 0;
        while(i <= j){
            if(people[i] + people[j] <= limit){
                i++;
                j--;
            }else{
                j--;
            }
            count++;
        }
        return count;
    }
};