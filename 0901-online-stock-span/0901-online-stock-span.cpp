class StockSpanner {
public:
    
    stack<pair<int,int>> st;  // value, days
    int n;
    
    StockSpanner() {
        n = 0;
    }
    
    // nearest greater to left algo
    // should store index of NGL element
    
    int next(int price) {
        int ngl;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        if(st.empty()){
            ngl = n + 1;
        }else{
            ngl = n - st.top().second;
        }
        st.push({price, n});
        n++;
        return ngl;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */