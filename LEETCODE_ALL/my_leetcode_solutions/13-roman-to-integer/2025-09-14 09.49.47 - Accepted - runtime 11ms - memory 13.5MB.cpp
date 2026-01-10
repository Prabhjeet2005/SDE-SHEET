class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> romanSet = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int number = 0;

        for(int i=0;i<s.size();i++){
            if(s[i] == 'I'){
                if(i+1 < s.size() && (s[i+1] == 'V' || s[i+1] == 'X')){
                    number += (romanSet[s[i+1]] - romanSet[s[i]]);
                    i++;
                }else{
                    number+= romanSet['I'];
                }
            }
            else if(s[i] == 'X'){
                if(i+1 < s.size() && (s[i+1] == 'L' || s[i+1] == 'C')){
                    number += (romanSet[s[i+1]] - romanSet[s[i]]);
                    i++;
                }else{
                    number+= romanSet['X'];
                }
            }
            else if(s[i] == 'C'){
                if(i+1 < s.size() && (s[i+1] == 'D' || s[i+1] == 'M')){
                    number += (romanSet[s[i+1]] - romanSet[s[i]]);
                    i++;
                }else{
                    number+= romanSet['C'];
                }
            }else{
                number += romanSet[s[i]];
            }
        }
        return number;
    }
};