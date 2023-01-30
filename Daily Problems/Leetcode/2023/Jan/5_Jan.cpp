452. Minimum Number of Arrows to Burst Balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
            if(points.empty())
                return 0;
            sort(points.begin(),points.end());
            
            int ans = 1, target = points[0][1];
            for(int i = 1; i < points.size(); i++){
                if(points[i][0] <= target)
                    target = min(target, points[i][1]);
                else{
                    ans++;
                    target = points[i][1];
                }
            }
        return ans;
    }
};