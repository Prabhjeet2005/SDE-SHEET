class Solution {
public:
    bool isPowerOfFour(int n) {
        int i=0;
        while(i<=30){
            if(pow(4,i)==n){
                return 1;
            }
            i++;
        }
        return 0;
    }
};