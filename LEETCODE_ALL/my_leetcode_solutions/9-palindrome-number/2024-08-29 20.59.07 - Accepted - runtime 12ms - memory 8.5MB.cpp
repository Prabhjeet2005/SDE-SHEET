class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }long  r=0;
        long  num=x;
        
        while(num!=0){
            int rem=num%10;
            r=r*10+rem;
            num/=10;
        }
        

        return r==x;
    }
};