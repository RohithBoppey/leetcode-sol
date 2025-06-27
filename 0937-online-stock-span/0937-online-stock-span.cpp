class StockSpanner {
public:
    stack<pair<int, int>> st; 
    int ind;
    StockSpanner() {
        ind = 0;
    }
    
    // each time, finding the left greater element
    int next(int price) {
        // keep popping until you an element which is greater than the current element
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int res;
        if(st.empty()){
            res = ind + 1;
        }else{
            res = ind - st.top().second; 
        }
        st.push({price, ind});
        ind++;
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */