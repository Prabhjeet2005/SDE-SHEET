class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        stack<char>stack;
        int currentDepth=0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                stack.push('(');
            }else if(s[i]==')'){
                stack.pop();
            }
            int size = stack.size();
            maxDepth = max(maxDepth,size);
        }
        return maxDepth;
    }
};