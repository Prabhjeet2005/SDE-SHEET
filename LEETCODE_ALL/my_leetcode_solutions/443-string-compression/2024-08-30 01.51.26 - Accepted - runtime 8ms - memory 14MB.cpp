class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0, index=0;
        while(i<chars.size()){
            int j=i+1;
            while(j<chars.size() && chars[i]==chars[j]){
                j++;
            }
            cout << j<<" ";
            chars[index++]=chars[i];
            int count = j-i;
            cout<<count<<" ";
            if(count>1){
                string cnt=to_string(count);
                
                for(char ch:cnt){
                    cout<<ch<<endl;
                    chars[index++]=ch;
            }
            }
            
            i=j;
        }
        return index;
    }
};