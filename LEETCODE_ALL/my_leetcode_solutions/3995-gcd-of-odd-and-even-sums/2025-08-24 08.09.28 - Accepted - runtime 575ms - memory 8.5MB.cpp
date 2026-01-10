class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long sumOdd = 0;
        long long sumEven = 0;
        for(int i=1; i<2*abs(n); i++){
            if(i&1)sumOdd+=i;
            else sumEven+=i;
        }

        long long mini = min(sumOdd,sumEven);
        int ans=1;
        for(int i = mini; i>=2;i--){
            if(sumOdd %i ==0 && sumEven%i==0){
                ans=i;break;
            }
        }
        return ans;
    }
};