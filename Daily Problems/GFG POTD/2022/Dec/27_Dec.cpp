Container With Most Water

long long maxArea(long long A[], int len)
{
    long long ans = 0, i = 0, j = len -1, res = 0;
    while(i<j){
        if(A[i] <= A[j]){
            res = A[i] * (j - i);
            i++;
        } else {
            res = A[j] * (j - i);
            j--;
        }
        if(res > ans)
            ans = res;
    }
    return ans;
}