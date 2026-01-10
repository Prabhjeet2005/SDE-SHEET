class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int nrow=matrix.size();
        int ncol=matrix[0].size();

        int startingRow=0;
        int startingCol=0;
        int endingRow=nrow-1;
        int endingCol=ncol-1;

        int count =0;
        int total= nrow*ncol;
        vector<int> ans;
        while(count<total){
            if(count<total){
                for(int i=startingCol; i<=endingCol; i++){
                    ans.push_back(matrix[startingRow][i]);
                    count++;
                }startingRow++;
            }
            if(count<total){
                for(int i=startingRow; i<=endingRow; i++){
                    ans.push_back(matrix[i][endingCol]);
                    count++;
                }endingCol--;
            }
            if(count<total){
                for(int i=endingCol; i>=startingCol; i--){
                    ans.push_back(matrix[endingRow][i]);
                    count++;
                }endingRow--;
            }
            if(count<total){
                for(int i=endingRow; i>=startingRow; i--){
                    ans.push_back(matrix[i][startingCol]);
                    count++;
                }startingCol++;;
            }
        }
        return ans;
    }
};