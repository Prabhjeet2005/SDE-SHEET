class Solution {
public:
    bool isValid(string s) {
        stack<char>brackets;
        if(s.size()%2==1)return false;

        for(int i=0; i<s.size();i++){
            char currentCh = s[i];
            if(currentCh == '(' ||currentCh == '[' ||currentCh == '{'){
                brackets.push(s[i]);
            }else{
                if(brackets.empty())return false;
                char topBracket = brackets.top();
                brackets.pop();
                if( currentCh == ')' && topBracket != '(' ){
                    return false;
                }else if( currentCh == '}' &&  topBracket != '{'){
                    return false;
                }else if( currentCh == ']' && topBracket != '[' ){
                    return false;
                }
            }
        }
        if(!brackets.empty())return false;
        return true;
    }
};