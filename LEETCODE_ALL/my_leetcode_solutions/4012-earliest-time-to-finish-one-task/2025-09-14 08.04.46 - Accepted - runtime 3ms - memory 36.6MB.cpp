class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int minTime = INT_MAX;
        if(tasks.size() == 1)return tasks[0][0] + tasks[0][1];

        for(auto &row:tasks){
           
                minTime = min(minTime,row[0] + row[1]);
            
        }
        return minTime;
    }
};