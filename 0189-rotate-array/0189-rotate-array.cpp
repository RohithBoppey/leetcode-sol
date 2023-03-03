class Solution {
public:
    void rotate(vector<int>& nums, int k)
	{
		k = k%nums.size();
		if(k == 0 || nums.size() == 1) return;
		vector<int> v;
		for(int i = nums.size()-k; i < nums.size(); ++i) v.push_back(nums[i]);
		int e = nums.size() -1;
		for(int i = nums.size()-k-1; i>=0; --i,--e) nums[e] = nums[i];
		for(int i = 0; i < v.size(); ++i) nums[i] = v[i];        
	}
};