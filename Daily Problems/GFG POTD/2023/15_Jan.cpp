Count the Substring

class Solution{
public:
  long long countSubstring(string S){
    int N = S.length(); 
    long long ans=0; 
    int sum = 0,not_one = 0; 
    unordered_map<int, int> mp; 
    for (auto x:S){
    	if(x=='1')
    	    sum++;
    	else 
    	    sum--;
    	if(sum<=0)
    	    not_one++;
    	mp[sum]++;
    }
    sum=0;
    for(int i=0;i<N;i++){ 
        ans+=(N-i-not_one); 
        if(S[i]=='1'){ 
            sum++;
            mp[sum]--; 
            not_one+=mp[sum];
        }else{
            sum--; 
            mp[sum]--;
            not_one--;
            not_one-=mp[sum+1];
        }
    }
    return ans;
  }