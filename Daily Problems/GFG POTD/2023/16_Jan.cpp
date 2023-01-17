Next Greater Element

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        vector<long long> ans(n,0);
        stack<long long> s;
        for(int i=n-1;i>=0;i--) {
            while(s.size()>0 && s.top()<=arr[i]) {
                s.pop();
            }
            if(s.size()==0) {
                ans[i]=-1;
            } else {
                ans[i]=s.top();
            }
            s.push(arr[i]);
        }
        return ans;
    }
};