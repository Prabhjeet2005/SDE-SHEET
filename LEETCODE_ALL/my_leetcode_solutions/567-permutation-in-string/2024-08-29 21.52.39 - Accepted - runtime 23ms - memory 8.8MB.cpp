class Solution {
public:
    bool check(int a[26], int b[26]){
        for(int i=0; i<26; i++){
            if(a[i]!=b[i])
            return 0;
        }return 1;
    }
    bool checkInclusion(string s1, string s2) {
        int c1[26]={0};
        int c2[26]={0};
        int window=s1.size();
        for(int i=0; i< s1.size(); i++){
            c1[s1[i]-'a']++;
        }
        int i=0;
        while(i<s1.size()&& i<s2.size()){
            c2[s2[i]-'a']++;
            i++;
        }cout<<"Check: "<<check(c1,c2)<<endl;
        if(check(c1,c2)){
            
            return 1;
        }

        while(i<s2.size() ){
            int newchar=s2[i]-'a';
            c2[newchar]++;
            int old=s2[i-s1.size()]-'a';
            c2[old]--;
            cout<<"Check "<<i<<" "<<check(c1,c2)<<endl;
            if (check(c1,c2)){
            return 1;
        }
            i++;
        }
        
        return 0;
    }
};