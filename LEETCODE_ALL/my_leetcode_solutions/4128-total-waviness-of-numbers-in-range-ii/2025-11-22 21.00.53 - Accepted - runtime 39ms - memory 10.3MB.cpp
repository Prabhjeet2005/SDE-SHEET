class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        long long answer =  solve(num2) - solve(num1-1);
        return answer;
    }
    private:
    string s;
    struct Result{
        long long count,wavy;
    }dp[17][11][4][2][2];

    Result dp_function(int index,int prev,int tr, bool ti, bool le){
        if(index == s.size())return {1,0};
        if(dp[index][prev][tr][ti][le].count!= -1)
        return dp[index][prev][tr][ti][le];

        long long tc = 0,tw=0,limit = ti ?( s[index] - '0'):9;

        for(int d = 0; d<= limit; d++){
            bool nt = ti && (d == limit),nl = le && !d;

            if(nl){
                Result res_obj = dp_function(index+1,10,0,nt,1);
                tc += res_obj.count;
                tw += res_obj.wavy;
            }else{
                int ntr = 0;
                int peak_or_valley = 0;
                if(prev != 10){
                    if(prev > d)ntr = 2;
                    else if(prev < d)ntr = 1;
                    else ntr= 3;

                    if(tr == 1 && prev > d || tr == 2 && prev < d)peak_or_valley = 1;
        }

                    Result res_obj = dp_function(index+1,d,ntr,nt,0);
                    tc += res_obj.count;
                    tw += res_obj.wavy + (res_obj.count * peak_or_valley);
                }
            }
            return dp[index][prev][tr][ti][le] = {tc,tw};
        }
        long long solve(long long n){
            if(n<=0)return 0;
            s = to_string(n);
            for(int i=0; i<17;i++)
                for(int j=0; j<11; j++)
                    for(int k=0; k<4; k++)
                        for(int l=0; l<2; l++)
                            for(int m=0; m<2; m++)
                                dp[i][j][k][l][m]={-1,-1};

            return dp_function(0,10,0,1,1).wavy;
    }
    
};