Convert an array to reduced form
Easy
Array, Pair

Time : O(N)

class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	   vector<pair<int,int>> v;
	    for(int i=0;i<n;i++)
	        v.push_back({arr[i],i});
	        
	    sort(v.begin(),v.end());
	    for(int i=0;i<n;i++)
	        arr[v[i].second]=i;
	}
};