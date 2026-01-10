class Solution {
public:
    int reverse(int x) {
            int remainder=0,numCpy=x,finalAns = 0;

            while(numCpy!=0){
                remainder = numCpy % 10;
                numCpy /= 10;
                if(finalAns > INT_MAX/10 || finalAns < INT_MIN/10){return 0;}
                finalAns = finalAns * 10 + remainder;
            }

            return finalAns;
        }

    
};