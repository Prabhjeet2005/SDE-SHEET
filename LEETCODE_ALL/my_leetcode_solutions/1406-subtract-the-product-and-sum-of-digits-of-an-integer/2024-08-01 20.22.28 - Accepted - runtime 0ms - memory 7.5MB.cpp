class Solution {
public:
    int subtractProductAndSum(int n) {
        int p=1,s=0;
        while(n!=0){
            int r=n%10;
            s+=r;
            p*=r;
            n/=10;
        }
        return p-s;
    }
};