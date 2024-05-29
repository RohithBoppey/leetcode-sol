+ The problem is to give at index `i`, we should return number of elements which are greater than nums[i] to the right.
+ The idea in here is: for the configuration [5,8,10,6] -> when dealing with stack length only, we are missing out on the case of 5 -> it will give only 8,10 as greater elements, but not 6
+ So inorder to tackle that - I am pushing whatever components that we have removed -> back, so essentially, stack at i contains all elements
+ BUT TLE is coming
+ So apparently should be solved using (Inversion Merge Sort)[]

```
class Solution{
public:

    // this is a modified function
    // this contains the number of NGE for a current index
    // this is same as pushing stack count for this
    
    void solve(vector<int>& arr, vector<int>& ng){
        int n = arr.size();
        ng.resize(n, 0);
        stack<int> st, temp;
        int e, t;
        for(int i = n - 1; i >= 0; i--){
            e = arr[i];
            if(st.empty()){
                // return 0
                ng[i] = 0;
                st.push(e);
            }else{
                // stack is not empty
                // contains elements
                // remove all numbers which are less than the current element 'e'
                while(!st.empty() && e >= st.top()){
                    t = st.top();
                    st.pop();
                    temp.push(t);
                }
                
                ng[i] = st.size();
                
                // insert the current one
                st.push(e);
                
                // insert back into the stack
                while(!temp.empty()){
                    t = temp.top();
                    temp.pop();
                    st.push(t);
                }
            }
        }
    }

    void printV(vector<int>& v){
        for(auto f: v){
            cout << f << " ";
        }
        cout << endl;
    }

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
       vector<int> ng_count;
       solve(arr, ng_count);
       // now the ng_count contains count of each
    //   printV(ng_count);
       vector<int> result;
       for(auto i: indices){
           result.push_back(ng_count[i]);
       }
       return result;
    }

};

```
