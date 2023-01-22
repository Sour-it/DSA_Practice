GCD Array

Medium
Array, GCD

Time complexity: O(N) +  O(sqrt(N)) + O(x*N)
Space complexity: O(x)

class Solution {
  public:
    void factor(vector<int>& arr, int n){
      for(int i = 1;i*i<=n;i++){
          if(n%i == 0){
              arr.push_back(i);
              if((n/i) != i)
                arr.push_back(n/i);
          }
      }
      return;
    }

    int solve(int N, int K, vector<int> &arr) {
        int all = 0, res = 1,temp,sum;
        vector<int> v;
        for(int i = 0;i<N;i++)  
            all += arr[i];
        factor(v, all);
        for(int i = 0;i<v.size();i++){
            temp = v[i];
            sum = 0;
            all = 0;
            for(int j = 0;j<N;j++){
                sum += arr[j];
                if(sum%temp == 0)    
                    all++;
            }
            if(all >= K)    
                res = max(res, temp);
        }
        return res;
    }
};
