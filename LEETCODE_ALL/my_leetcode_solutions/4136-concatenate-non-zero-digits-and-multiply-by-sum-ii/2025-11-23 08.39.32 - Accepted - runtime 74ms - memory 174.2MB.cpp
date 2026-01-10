class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9+7;

        vector<long long>ps(m+1,0),pc(m+1,0),pv(m+1,0),pow(m+1,1);
        vector<int>result;

        for(int i=0; i<m; i++){
            int d = s[i] - '0';
            ps[i+1] = ps[i] + d;

            if(d!= 0){
                pc[i+1] = pc[i]+1;
                pv[i+1] = (pv[i]*10+d)%MOD;
                
            }else{
                pc[i+1] = pc[i];
                pv[i+1] = pv[i];
            }
            pow[i+1] = (pow[i]*10)%MOD;
        }

        for(auto q:queries){
            int li = q[0],ri=q[1];
            long long cs = ps[ri+1]-ps[li],cnt = pc[ri+1]-pc[li];
            if(cnt == 0){
                result.push_back(0);continue;
            }

            long long t = (pv[li]*pow[cnt])%MOD;
            long long cx = (pv[ri+1]-t + MOD)%MOD;
            long long ans = (cx*(cs%MOD))%MOD;
            result.push_back((int)ans);
        }
        return result;
    }
};