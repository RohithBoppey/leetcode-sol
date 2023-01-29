
class SummaryRanges {
public:
    vector<vector<int>> intervals; 
    SummaryRanges() {
        
    }
    
    void modifiedMergeIntervals(){
        sort(intervals.begin(), intervals.end());
        int i = 0;
        int n = intervals.size();
        while(i != n - 1){
            if(intervals[i][1] + 1 >= intervals[i+1][0]){
                intervals[i][1] = max(intervals[i][1], intervals[i+1][1]);
                intervals.erase(intervals.begin() + i + 1);
                n--;
            }else{
                i++;
            }
        }
    }
    
    void addNum(int value) {
        intervals.push_back({value, value});
        modifiedMergeIntervals();
    }
    
    vector<vector<int>> getIntervals() {
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */