class Solution {
public:
    struct CustomCompare{
        bool operator()(const pair<char, int>& p1, const pair<char, int>& p2){
            return p1.second < p2.second; 
        }
    };

    void print(auto& t){
        while(!t.empty()){
            auto top = t.top();
            cout << top.first << " " << top.second << endl;
            t.pop();
        }
    }

    string longestDiverseString(int a, int b, int c) {
        priority_queue<
        pair<char, int>, 
        vector<pair<char, int>>, 
        CustomCompare
        > pq;

        string ans = "";

        // push the ones in the pq
        if (a > 0) pq.push({'a', a});
        if (b > 0) pq.push({'b', b});
        if (c > 0) pq.push({'c', c});

        // print(pq);
        pair<char, int> prim, second;
        int count = 0;
        char ch = 'X'; 

        while(!pq.empty()){
            prim = pq.top(); 
            pq.pop(); 

            // cout << prim.first << " " << prim.second << endl;

            int len = ans.size();
            if(len >= 2 && ans[len - 1] == prim.first && ans[len - 2] == prim.first){
                // use the secondary, skip primary
                if(!pq.empty()){
                    second = pq.top();
                    pq.pop();

                    ans += second.first;
                    second.second = second.second - 1;

                    // repush second
                    if(second.second > 0) pq.push(second);
                    count = 1;
                    ch = second.first;
                }else{
                    break;
                }
            }else{
                // meaning last 2 are not same, hence use primary only
                ch = prim.first;
                ans += ch; 

                // remove one letter from primary
                prim.second = prim.second - 1;
            }

            if(prim.second > 0) pq.push(prim);
        }


        return ans;
    }
};