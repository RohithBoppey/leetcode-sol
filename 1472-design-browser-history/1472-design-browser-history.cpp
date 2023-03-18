class BrowserHistory {
public:
    vector<string> sites;
    int curr;
    
    BrowserHistory(string homepage) {
        sites.clear();
        sites.push_back(homepage);
        curr = 0;
    }
    
    void visit(string url) {
        if(curr != sites.size() - 1){
            sites.erase(sites.begin() + curr + 1, sites.end());
        }
        sites.push_back(url);
        curr++;
    }
    
    string back(int steps) {
        while(steps > 0 && curr > 0){
            steps--;
            curr--;
        }
        return sites[curr];
    }
    
    string forward(int steps) {
        while(steps > 0 && curr < sites.size() - 1){
            steps--;
            curr++;
        }
        return sites[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */