class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        long reverse = 0,remainder = 0,number = x;
        while(number != 0){
            remainder = number % 10;
            number /= 10;
            reverse = reverse * 10 + remainder;
        }
        if(reverse == x){
            return true;
        }
        return false;
    }
};