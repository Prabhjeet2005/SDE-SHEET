class Solution {
    bool isRotateSame(string &temp, string & goal,int index){
        reverse(temp.begin(),temp.begin()+index);
        reverse(temp.begin()+index,temp.end());
        reverse(temp.begin(),temp.end());
        if(temp == goal){
            return true;
        }
        return false;
    }
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())return false;
        for(int i=0; i<goal.size(); i++){
            string temp = s;
            if(isRotateSame(temp,goal,i))return true;
        }
        return false;

    }
};