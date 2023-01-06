Maximum Profit By Choosing A Subset Of Intervals

class Solution {
  public:
     static bool func(vector<int> &a,vector<int> &b){
        if(a[1]<b[1])return true;
        else if(a[1]>b[1])return false;
        else{
            return a[0]<=b[0];
        }
    }
    
    int binarySearch(vector<vector<int>> &intervals,int length,int key){
        int start=0,end=length,mid,index=-1;
        while(start<=end){
            mid = (start+end)/2;
            if(intervals[mid][1]<=key){
                index=mid;
                start=mid+1;
            }
            else end=mid-1;
        }
        return index;
    }
    
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        sort(intervals.begin(),intervals.end(),func);
        vector<int> ans(n,0);
        ans[0]=intervals[0][2];
        for(int i=1;i<n;i++){
            int index = binarySearch(intervals,i-1,intervals[i][0]);
            if(index==-1){
                ans[i]=intervals[i][2];
            }
            else{
                ans[i]=ans[index]+intervals[i][2];
            }
            ans[i]=max(ans[i],ans[i-1]);
        }
        return ans[n-1];
    }
};