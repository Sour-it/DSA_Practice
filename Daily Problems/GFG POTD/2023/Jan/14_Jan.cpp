Maximum Number of Toys

class Solution{
public:
  vector<int> maximumToys(int N,vector<int> A,int Q,vector<vector<int>> Queries){
    vector<pair<int, int>> arr;
    vector<long long int> sum(N,0);
    
    for(int i=0;i<N;i++)
    	arr.push_back({A[i],i});
    
    sort (arr.begin(), arr.end());
    sum[0]=arr[0].first;
    for (int i=1;i<N;i++)
    	sum[i]+=sum[i-1]+arr[i].first;
    vector<int> ans;
    
    for (auto x:Queries){
    	int cst=x[0];
    	int index = lower_bound(sum.begin(), sum.end(), cst) - sum.begin();
    	if(index==0 and sum[0] > cst){
    		ans.push_back(0);
    		continue;
    	}
    	if(index==N)
    		index--;
    	if(sum[index]>cst)
    		index--;
    	int toys = index+1;
    	cst -= sum[index];
    	int j=2;
    	unordered_set<int> bk_toys; 
    	while(j<x.size()){
    		int broken = x[j]-1;
    		bk_toys.insert(broken);
    		if(A[broken]<arr[index].first){
    			toys--;
    			cst+=A[broken];
    		}
    		else if(A[broken] == arr[index].first and broken<=arr[index].second){
    			toys--;
    			cst+=A[broken];
    		}
    		j++;
    	}
    	int i=index+1;
    	for(int i=index+1;i<N and cst>=arr[i].first;i++){
    		if(bk_toys.find(arr[i].second)==bk_toys.end()){
    			toys++;
    			cst-=arr[i].first;
    		}
    	}
    	ans.push_back(toys);
    }
    return ans;
  }