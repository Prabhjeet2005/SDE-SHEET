class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](const vector<int>&a,const vector<int>&b){return a[0]<b[0];});

        if(intervals.size() == 1){
            return intervals;
        }

        vector<vector<int>>ans;

        for(int i=0; i<intervals.size(); i++){
            if(ans.empty()){
                ans.push_back(intervals[i]);
                continue;
            }
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start <= ans.back()[1]){
                ans.back()[1] = max(end,ans.back()[1]);
            }else{
                ans.push_back({start,end});
            }
        }

        
        return ans;
    }
};