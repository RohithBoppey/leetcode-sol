```c++
  //#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>

#define pb push_back
#define ll long long int

using namespace std;

/*-------------------------------------------
--------------Rohith's Solution--------------
---------------------------------------------*/

#define maxX(a,b) (a>b?a:b)
#define minX(a,b) (a<b?a:b)
#define isEven(a) ((a%2==0)?1:0)
#define isOdd(a) ((a%2==0)?0:1)
#define isNeg(a) ((a<0)?1:0)
#define loop(n) for(int i = 0; i < n; i++)
#define loop2(n) for(int j = 0; j < n; j++)

vector<int> scanVector(int n){
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    return v;
}

void printVector(vector <int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "" << endl;
}

void printInRange(vector<int>& v, int start, int end){
    for(int i = start; i <= end; i++){
        cout << v[i] << " ";
    }
    cout << "" << endl;
}

void SlidingWindow(vector<int>& v, int k){
    int n = v.size();
    int i = 0, j = 0;
    int l;
    while(j < n){
        l = j - i + 1;
        if(l < k){
            // size not met
            cout << "Not met, size: " << l << endl;
            printInRange(v, i, j);
        }else{
            // size met
            printInRange(v, i, j);
            i++;
        }
        j++;
    }
}

void Sol(){
    vector<int> v = scanVector(5);
    printVector(v);
    SlidingWindow(v, 3);
}

void RepSolution(){
    int t;
    cin >> t;
    while(t!=0){
        Sol();
        t--;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //RepSolution();
    Sol();
    return 0;
}
```
