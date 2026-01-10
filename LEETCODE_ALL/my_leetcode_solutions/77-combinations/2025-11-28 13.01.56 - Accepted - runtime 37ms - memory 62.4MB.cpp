class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>final_ans;
        vector<int>curr;

        find_combo(n,k,1,final_ans,curr);

        return final_ans;
    }
    private:
    void find_combo(int n,int k, int index,vector<vector<int>>&final_ans,vector<int>&curr){
        if(curr.size() >= k ){
            final_ans.push_back(curr);
            return;
        }

        for(int i=index; i<=n; i++){
            curr.push_back(i);
            find_combo(n,k,i+1,final_ans,curr);
            curr.pop_back();

        }
    }
};