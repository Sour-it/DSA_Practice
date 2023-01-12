Minimize the sum

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        priority_queue<int, vector<int>, greater<int>> q;
        int sum = 0,temp = 0, temp2 = 0;
        for(int i = 0; i < N; i++)
            q.push(arr[i]);
        while(q.size() > 1){
            temp = q.top();
            q.pop();
            temp2 = q.top();
            q.pop();
            sum+=(temp+temp2);
            q.push(temp+temp2);
        }
        return sum;
    }
};