class Solution {
public:
    int countEffective(vector<int>& nums) {
        long long MOD = 1e9+7;
        int n = nums.size(),s=0;
        for(auto num:nums)s = s | num;


        int nb = 0;
        while((1<<nb)<=s)nb++;
        
        int limit = 1<<nb;
        vector<long long>fi(limit,0);

        for(auto x:nums)fi[x]++;

        for(int i=0; i<nb; i++)
            for(int j=0; j<limit; j++){
                if(j & ( 1<<i))fi[j] += fi[j^(1<<i)];
            }

        vector<long long> power_2(n+1);
        power_2[0]=1;
        for(int i=1; i<n+1;i++)power_2[i] = (power_2[i-1]*2)%MOD;

        long long count = 0;
        int pops = __builtin_popcount(s); 

        for(int i=0; i<s+1; i++){
            if((i | s)==s){
                int pop = __builtin_popcount(i);
                long long difference = pops - pop;

                long long paths = power_2[fi[i]];

                if(difference % 2 == 1)count = (count - paths + MOD) % MOD;
                else count = (count+paths) % MOD;
            }
        }

        long long all_sets = power_2[nums.size()],final_ans = (all_sets - count + MOD)%MOD;
        return final_ans;
    }
};