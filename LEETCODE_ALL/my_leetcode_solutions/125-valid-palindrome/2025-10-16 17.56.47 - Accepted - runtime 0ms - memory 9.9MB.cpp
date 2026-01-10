class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0,right = s.size()-1;
        for(int i=0; i<s.size();i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = (char)((int)(s[i] - 'A') + 'a');
            }
        }

        while(left < right){
            while(left < right && !isalnum(s[left]))left++;
            while(right > left && !isalnum(s[right]))right--;

            if(s[left] != s[right])return false;

            left++;right--;
        }

        return true;
    }
};