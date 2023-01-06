Minimize number of Students to be removed

class Solution {
  public:
      int removeStudents (int H[], int N) {
    	vector<int>v;
    	for(int i=0; i<N; i++){
    		int idx = lower_bound(v.begin(),v.end(), H[i]) - v.begin();
    		if (idx==v.size()) 
    			v.push_back(H[i]);
    		else{
    			v[idx] = H[i];
    		}
    	}
    	return N-v.size();
    }
};