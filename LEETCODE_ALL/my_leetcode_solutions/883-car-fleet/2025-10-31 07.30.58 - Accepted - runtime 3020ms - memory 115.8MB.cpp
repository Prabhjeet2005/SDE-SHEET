class Solution {
    bool static custom_operator(const pair<int, int> pair1,
                         const pair<int, int> pair2) {

            return pair1.first > pair2.first;

    }

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> position_speed;

        for (int i = 0; i < position.size(); i++) {
            position_speed.push_back({position[i], speed[i]});
        }

        sort(position_speed.begin(), position_speed.end(), custom_operator);

        vector<double>time;
        for(int i=0;i<position_speed.size();i++){
            double current_time = (double)(target - position_speed[i].first)/(double)position_speed[i].second;
            time.push_back(current_time);
        }

        for(auto it:position_speed){
            cout<<"{"<<it.first<<","<<it.second<<"}";
        }

        for(auto &it:time){
            cout<<it<<" ";
        }

        stack<double>fleets;
        for(int i=0; i<time.size();i++){
            if(fleets.empty()){
                fleets.push(time[i]);
                continue;
            }
            if(time[i] > fleets.top()){
                fleets.push(time[i]);
            }
        }

        return fleets.size();
    }
};