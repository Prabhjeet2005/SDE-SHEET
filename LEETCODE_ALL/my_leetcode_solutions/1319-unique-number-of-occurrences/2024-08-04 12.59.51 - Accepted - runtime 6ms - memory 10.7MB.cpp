class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> ans;
        int i=0;
        sort(arr.begin(),arr.end());
        while(i<arr.size()){
            int count=1;
            for(int j=i+1; j<arr.size();j++){
                if(arr[i]==arr[j]){
                    count++;
                }
            }
            ans.push_back(count);
            i+=count;
        }
        sort(ans.begin(),ans.end());
        for(int i=0; i<ans.size()-1; i++){
            if(ans[i]==ans[i+1]){
                return false;
            }
        }
        return true;
    }
};