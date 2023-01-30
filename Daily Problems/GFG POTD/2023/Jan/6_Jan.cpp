Shortest Prime Path

class Solution{   
  public:
    bool isPrime(int n){
        if (n <= 1)
            return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i <= sqrt(n); i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }
    
    int shortestPath(int Num1,int Num2){   
        unordered_set<int> sn; 
    	queue<int> q; 
    	q.push(Num1); 
    	sn.insert(Num1); 
    	int ans = 0; 
    	while(q.size()){
    		int sze = q.size(); 
    		while(sze--){
    			int n = q.front();
    			q.pop();
    			if(n == Num2) return ans;
    			for(int i=0;i<4;i++){
    				int fac = pow(10,i);
    				int temp = n;
    				temp -= (fac * ((temp/fac)%10));
    				for(int j = 0; j<=9;j++){
    					temp += (fac * j);
    					if(temp>1000 && !sn.count(temp) && isPrime(temp)){
    						q.push(temp);
    						sn.insert(temp);
    					}
    					temp -= (fac * j);
    				}
    			}
    		}
    		ans++;
    	}
	    return -1;
    }
};
