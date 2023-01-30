Asteroid Collision

class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        vector <int> sim;
        for(int i = 0; i < asteroids.size(); i++){
            if(asteroids[i] > 0 || sim.empty() || sim.back() < 0)
                sim.push_back(asteroids[i]);
            else if(sim.back() <= -asteroids[i]){
                if(sim.back() < -asteroids[i]) 
                    i--;
                sim.pop_back();
            }
        } 
        return sim;
    }
};