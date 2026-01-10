class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0, index=0, n=chars.size();
        while(i<n){
            int j=i+1;
            while(j<n && chars[i]==chars[j]){
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