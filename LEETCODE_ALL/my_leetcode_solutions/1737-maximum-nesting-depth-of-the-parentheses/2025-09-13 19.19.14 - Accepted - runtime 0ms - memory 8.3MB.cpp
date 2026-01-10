class Solution {
public:
    int maxDepth(string s) {
        int maxCount=0,currentCount=0;
        for(auto character:s){
            if(character == '('){
                currentCount++;
            }else if(character == ')'){
                currentCount--;
            }
            maxCount = max(currentCount,maxCount);
        }
        return maxCount;
    }
};