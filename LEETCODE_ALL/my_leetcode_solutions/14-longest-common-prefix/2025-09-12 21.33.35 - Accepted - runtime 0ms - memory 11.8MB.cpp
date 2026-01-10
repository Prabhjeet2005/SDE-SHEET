class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minStrSize = INT_MAX,cnt=0;
        if(strs.size() == 1)return strs[0];

        string temp = "" ,ans="";
        for(int i=0; i<strs.size();i++){
            if(minStrSize > strs[i].size()-1){
                minStrSize = strs[i].size()-1;
                temp = strs[i];
            }
        }

        for(int i=0;i<strs.size();i++){
            for(int j=0; j<=minStrSize; j++){
                if(strs[i][j] != temp[j]){
                    minStrSize = j-1;
                    temp = strs[i].substr(0,j);
                }
            }
        }
        if(minStrSize < 0)return "";

        return temp;


    }
};