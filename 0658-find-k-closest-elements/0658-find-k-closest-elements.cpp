class Solution {
public:

    void printv(vector<int>& v){
        for(auto &x: v){
            cout << x << " ";
        }
        cout << endl;
    }

    void print2d(vector<vector<int>>& v){
        for(auto &x: v){
            printv(x);
        }
    }

    int n;
    // binary search to give the closest
    int closest(vector<int>& arr, int x){
        int low = 0, high = n - 1, mid;

        // boundary condition
        if(arr[0] >= x){
            return 0;
        }

        if(arr[n - 1] <= x){
            return n - 1;
        }
 
        while(low < high){
            mid = low + (high - low) / 2;
            // cout << low << " " << high << " " << mid << endl;
            if(arr[mid] == x){
                return mid;
            }
            if(arr[mid] > x){
                // reduce space
                high = mid;
            }else{
                low = mid + 1;
            }
        }

        // meaning high = low
        return low; 
    }


    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        n = arr.size(); 
        // using binary search to find the index
        int index = closest(arr, x);
        
        // cout << index << endl; 
        cout << lower_bound(begin(arr), end(arr), x) - begin(arr) << endl;
        
        // now using the 2 pointers to find out the least k values
        int left = index - 1, right = index; 
        int lv, rv; 

        while(k > 0){
            lv = (left >= 0) ? x - arr[left] : INT_MAX;
            rv = (right <= n - 1) ? arr[right] - x : INT_MAX;

            if(lv <= rv){
                // go left after including this
                ans.push_back(arr[left]);
                left--;
            }else{ 
                ans.push_back(arr[right]);
                right++;
            }
            k--;
        }

        // sort the result
        sort(ans.begin(), ans.end());

        return ans;   
    }
};