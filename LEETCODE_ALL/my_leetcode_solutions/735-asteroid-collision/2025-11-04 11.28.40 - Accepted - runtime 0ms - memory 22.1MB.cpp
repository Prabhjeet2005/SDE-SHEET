class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> surviving_asteroids_stack;

        for(int i=0; i<asteroids.size();i++){
            // Only condition because there is collision 
            // if already present asteroid Left->right(+) and new_asteroid Left<-Right(-)
            bool asteroid_survives = true;
            while(!surviving_asteroids_stack.empty() && asteroids[i] < 0 && surviving_asteroids_stack.top() > 0){
                if(abs(asteroids[i]) == abs(surviving_asteroids_stack.top())){
                    // both explode
                    surviving_asteroids_stack.pop();
                    asteroid_survives = false;
                }else if(abs(asteroids[i]) < abs(surviving_asteroids_stack.top())){
                    // new asteroid explode
                    asteroid_survives = false;
                }else{
                    // old asteroid explode
                    surviving_asteroids_stack.pop();
                }
                if(!asteroid_survives)break;
            }
            if(asteroid_survives){
                surviving_asteroids_stack.push(asteroids[i]);
            }
        }
        vector<int>ans;
        while(!surviving_asteroids_stack.empty()){
            ans.push_back(surviving_asteroids_stack.top());
            surviving_asteroids_stack.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};