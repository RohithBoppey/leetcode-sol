![WhatsApp Image 2023-07-17 at 16 09 19](https://user-images.githubusercontent.com/73538974/253916864-eecbe819-86b0-48d1-b494-80240c7a0049.jpg)
![WhatsApp Image 2023-07-17 at 16 09 19](https://user-images.githubusercontent.com/73538974/253916889-c1289ae7-7466-4ebe-812e-ec9a4a5f1093.jpg)
        
```
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	
    	// sorting arrival and departure independently
    	// because we are concerned more about at a time how many platforms do we need
    	
    	sort(arr, arr + n);
    	sort(dep, dep + n);
    	
    	int mx = 0, curr = 0;
    	
    	int i = 0, j = 0;
    	
    	while(i < n && j < n){
    	    
    	    if(arr[i] > dep[j]){
    	        curr--;
    	        j++;
    	    }
    	    else if(arr[i] <= dep[j]){
    	       curr++;
    	       mx = max(curr, mx);
    	       i++;
    	    }
    	    
    	}
    	
    	return mx;
    }
};

```
