class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        string ans = "";
        int startSpace=0,endSpace=0;
        for(int i=0;i<size;i++){
            if (s[i] != ' '){
                startSpace = i;
                break;
            }
            
        }
        s.erase(0,startSpace);
        for(int i=s.size()-1;i>=0;i--){
            if (s[i] != ' '){
                endSpace = i;
                break;
            }
        }
        s.erase(endSpace+1,s.size()-endSpace-1);
        size = s.size();
        int left = size - 1, right = size - 1;
        while (left >= 0) {
            char ch = s[left];
            if (left != size-1 && ch == ' ' && s[left + 1] == ' ') {
                left--;
                continue;
            }
            if (ch == ' ' && left != size - 1) {
                ans += s.substr(left + 1, right - (left + 1) + 1) + " ";
            } else if (ch != ' ' && left != size - 1 && s[left + 1] == ' ') {
                right = left;
            }
            left--;
        }
        ans += s.substr(0, right + 1);
        return ans;
    }
};