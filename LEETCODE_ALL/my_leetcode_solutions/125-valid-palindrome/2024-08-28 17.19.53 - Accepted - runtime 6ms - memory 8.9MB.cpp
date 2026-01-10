class Solution {
public:
    
    bool isPalindrome(string s) {
        int start=0,e=s.length()-1,i=0;
        while(i<s.length()){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]=s[i]-'A'+'a';
            }i++;
        }
        cout<<s;
        start=0;
        while(start<e){
            if(s[start]==s[e]){
                start++;e--;
            }while(!isalnum(s[start]) && start<e){
                start++;
            }while(!isalnum(s[e])&& start<e){
                e--;
            }
            if(s[start]!=s[e]){
                return false;
            }
        }
        return true;
    }
};