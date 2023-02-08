class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//         solution involving counting of consequtive zereos
        if(n == 0){
//             no need to place
            return true;
        }
        
        for(int i = 0; i < flowerbed.size(); i++){
//             check if the neighbouring states are empty
//             3 major conditions
//             should be 0
//             on the left should be 0 or should be the first ele
//             on the right should be 0 or should be the last element
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)){
//                 can place
                n--;
                if(n == 0){
//                     nothing to place
//                     so all are done and can return
                    return true;
                }
//                 place the flower now
                flowerbed[i] = 1;
            }
        }
        
        
        return false;
    }
};