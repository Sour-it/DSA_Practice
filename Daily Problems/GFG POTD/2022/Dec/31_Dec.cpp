Find minimum number of Laptops required

class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        sort(start, start + N);
        sort(end, end + N);
        int total = 0, maxi = 0, i = 0, j = 0;
        while(i < N && j < N){
            if(start[i] < end[j]){
                i++;
                total++;
            }else {
                j++;
                total--;
            }
            maxi = max(total,maxi);
        }
        return maxi;
    }
};