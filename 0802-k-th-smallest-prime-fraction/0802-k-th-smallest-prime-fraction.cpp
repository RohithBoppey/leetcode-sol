struct Compare {
    bool operator()(const pair<double, vector<int>>& p1, const pair<double, vector<int>>& p2) {
        return p1.first < p2.first;  
    }
};

class Solution {
public:

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // using custom comparator for the problem
        priority_queue<  pair<double, vector<int>  >, vector<  pair<double, vector<int>> >, Compare> pq;
        
        // add all the elements in the max heap
        int n = arr.size();
        double dec;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                dec = (double) arr[i] / arr[j];
                // cout << arr[i] << " " << arr[j] << " " << dec << endl; 
                pq.push({dec, {arr[i], arr[j]}});

                // adjust the max heap accordingly to the k
                if(pq.size() > k){
                    pq.pop();
                }

            }
        }

        return pq.top().second;
    }
};