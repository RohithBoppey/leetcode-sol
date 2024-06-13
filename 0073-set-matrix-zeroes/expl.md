most bruteforce solution i can think of:
​
```
class Solution {
public:
void setZeroes(vector<vector<int>>& matrix) {
int rows = matrix.size();
int cols = matrix[0].size();
vector<int> rowm;
vector<int> colm;
for(int i = 0; i < rows; i++){
for(int j = 0; j < cols; j++){
if(matrix[i][j] == 0){
// found a 0
rowm.push_back(i);
colm.push_back(j);
}
}
}
for(auto row: rowm){
for(int i = 0; i < cols; i++){
matrix[row][i] = 0;
}
}
for(auto col: colm){
for(int i = 0; i < rows; i++){
matrix[i][col] = 0;
}
}
}