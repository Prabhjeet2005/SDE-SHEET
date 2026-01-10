class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> ans(n,vector<int>(n,0));
        int startingRow=0;
        int endingRow=n-1;
        int startingCol=0;
        int endingCol=n-1;
        int total=n*n;
        int count=1;
        while(count<=total){
            if(count<=total){
                for(int i=startingCol; i<=endingCol; i++){
                ans[startingRow][i]=count;count++;
            }startingRow++;
            }
            if(count<=total){
                for(int i=startingRow; i<=endingRow; i++){
                    ans[i][endingCol]=count;count++;
                }endingCol--;
            }
            if(count<=total){
                for(int i=endingCol; i>=startingCol;i--){
                    ans[endingRow][i]=count;count++;
                }endingRow--;
                
            }
            if(count<=total){
                for(int i=endingRow; i>=startingRow; i--){
                    ans[i][startingCol]=count;count++;
                }startingCol++;
            }

            // endingCol=

            
        }
        
        return ans;
    }
};