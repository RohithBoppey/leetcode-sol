class MedianFinder {
public:
    priority_queue<int> large, small;
    
    // small contains smaller part of the array -> to return median, it should be of type MAX HEAP
    // large contains larger part of the array -> to return median, it should be of the type MIN HEAP
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if(small.size() < large.size()){
            small.push(-large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        return small.size() > large.size() ? 
            small.top() : (double)(small.top() - large.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */