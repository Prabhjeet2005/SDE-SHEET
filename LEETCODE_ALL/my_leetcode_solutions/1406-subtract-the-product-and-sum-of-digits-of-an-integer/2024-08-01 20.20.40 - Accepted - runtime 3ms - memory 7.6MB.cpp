class Solution {
public:
    int subtractProductAndSum(int n) {
        int p=1,s=0,r;
        while(n!=0){
            r=n%10;
            s+=r;
            p*=r;
            n/=10;
        }
        return p-s;
    }
};