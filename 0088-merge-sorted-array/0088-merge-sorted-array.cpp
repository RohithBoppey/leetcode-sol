class Solution {
public:
    void swap1(vector<int>& a, int index1, vector<int>& b, int index2){
        if(a[index1] > b[index2]){
            swap(a[index1], b[index2]);
        }
    }
    
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        // Write your code here.
        // best optimal one - using GAP OR shell sort algorithm
        int len = n + m;

        // Initial gap:
        int gap = (len / 2) + (len % 2);

        while (gap > 0) {
            // Place 2 pointers:
            int left = 0;
            int right = left + gap;
            while (right < len) {
                // case 1: left in arr1[]
                //and right in arr2[]:
                if (left < m && right >= m) {
                    swap1(a, left, b, right - m);
                }
                // case 2: both pointers in arr2[]:
                else if (left >= m) {
                    swap1(b, left - m, b, right - m);
                }
                // case 3: both pointers in arr1[]:
                else {
                    swap1(a, left, a, right);
                }
                left++, right++;
            }
            // break if iteration gap=1 is completed:
            if (gap == 1) break;

            // Otherwise, calculate new gap:
            gap = (gap / 2) + (gap % 2);
        }
        
        // nums2 is sorted
        // hence we need to copy
        for(int i = 0; i < n; i++){
            a[m + i] = b[i];
        }
    }
};