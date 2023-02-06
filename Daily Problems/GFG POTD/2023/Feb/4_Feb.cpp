Max Sum without Adjacents
Easy

Array, Math

class Solution{
public:	
	int findMaxSum(int *arr, int n) {
	    
        int res=0, max1=0, max2=0, temp;
        
        for(int i=0;i<n;i++) {
            temp = arr[i]+max1;
            max1 = max(max1,max2);
            max2 = max(max2,temp);
            res = max(res,temp);
        }
        
        return res;
	}
};