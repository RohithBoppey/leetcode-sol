class Solution {
public:
    void printVector(vector<int> v){
        for(auto x: v){
            cout << x << " ";
        }
        cout << endl;
    }
    
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0){
            return true;
        }
        if(n > flowerbed.size()){
            return false;
        }
        if(flowerbed.size() == 1 && n == 1 && flowerbed[0] == 0){
            return true;
        }
        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i] == 0){
//                 can place
//                 if((i == 0 && flowerbed[i + 1] == 0) || i == flowerbed.size() - 1 && flowerbed[i - 1] == 0 || (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)){
// //                     can place now
//                     flowerbed[i] = 1;
//                     // printVector(flowerbed);
//                     n--;
//                     if(n == 0){
//                         return true;
//                     }
//                 }
                if(i == 0){
                    if(flowerbed[i + 1] == 0){
                        flowerbed[i] = 1;
                        // printVector(flowerbed);
                        n--;
                        if(n == 0){
                            return true;
                        }
                    }
                }else if(i == flowerbed.size() - 1){
                    if(flowerbed[i - 1] == 0){
                        flowerbed[i] = 1;
                        // printVector(flowerbed);
                        n--;
                        if(n == 0){
                            return true;
                        }
                    }
                }else{
                    if(flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0){
                        flowerbed[i] = 1;
                        // printVector(flowerbed);
                        n--;
                        if(n == 0){
                            return true;
                        }
                    }
                }
            }
        }
        
        return false;
    }
};