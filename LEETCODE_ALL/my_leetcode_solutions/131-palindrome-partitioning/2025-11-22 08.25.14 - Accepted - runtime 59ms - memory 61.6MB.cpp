class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>final_ans;
        vector<string>curr_string;

        find_palindrome_partition(s,0,curr_string,final_ans);

        return final_ans;
    }
    
    private:
    void find_palindrome_partition(string s,int index,vector<string>& curr_string,vector<vector<string>> &final_ans){
        if(index >= s.size()){
            final_ans.push_back(curr_string);
            return;
        }

        for(int i=index; i<s.size(); i++){
            if(is_palindrome(s,index,i)){
                curr_string.push_back(s.substr(index,i-index+1));
                find_palindrome_partition(s,i+1,curr_string,final_ans);
                curr_string.pop_back();
            }
        }
    }

    bool is_palindrome(string s,int start,int end){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;end--;
        }
        return true;
    }
};