class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long ts = (long long) n*(n+1)/2, diff = ts - target;

        if(diff % 2!= 0 || diff < 0)return {};

        long long k = diff/2;
        vector<int>res;
        vector<bool>is_neg(n+1,0);

        for(int i=n;i>0;i--){
            if(k>=i){
                k-=i;
                is_neg[i] = 1;
                res.push_back(-i);
            }
        }

        if(k>0)return {};

        for(int i=1; i<n+1; i++){
            if(!is_neg[i])res.push_back(i);
        }
        return res;
    }
};