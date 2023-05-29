class ParkingSystem {
public:
    
    vector<int> sys;
    
    ParkingSystem(int big, int medium, int small) {
        sys.resize(3,0);
        sys[0] = big;
        sys[1] = medium;
        sys[2] = small;
    }
    
    bool addCar(int carType) {
        if(sys[carType - 1] == 0){
            return false;
        }
        sys[carType - 1]--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */