class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>ans;
        solve(n,ans);
        return ans;
    }

    private:
    void solve(int n, vector<int>&ans){
        if(n<=1){
            ans.push_back(0);
            ans.push_back(1);
            return;
        }

        solve(n-1,ans);
        vector<int>copy(ans);
        reverse(copy.begin(),copy.end());
        for(auto &element: copy){
            element = element | 1 << (n-1);
        }
        for(auto &el:copy){
            ans.push_back(el);
        }
    }
};