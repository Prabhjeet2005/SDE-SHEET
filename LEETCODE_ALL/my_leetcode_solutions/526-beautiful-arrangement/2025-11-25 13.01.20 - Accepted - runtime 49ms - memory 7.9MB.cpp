class Solution {
public:
    int countArrangement(int n) {
        int count = 0;
        vector<bool>visited(n+1,false); // So directly 1-based index used
        int curr_pos = 1;
        count_beauty(n,count,visited,curr_pos);
        return count;
    }

    private:
    void count_beauty(int n, int &count,vector<bool>&visited,int curr_pos){
        if( curr_pos > n){
            count++;
            return ;
        }

        for(int i=1; i<=n; i++){
            if(visited[i])continue;
            if(( curr_pos % i == 0 ) || (i % curr_pos ==0)){
                visited[i]=1;
                count_beauty(n,count,visited,curr_pos+1);
                visited[i]=0;
            }
           
        }

    }
};