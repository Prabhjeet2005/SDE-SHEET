class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        int startingRow=0;
        int startingCol=0;
        int endingRow=row-1;
        int endingCol=col-1;

        int total=row*col;
        int count=0;
        vector<int> ans;
        while(count<total){
            if(count<total){
                for(int index=startingCol ; index<=endingCol; index++ ){
                ans.push_back(matrix[startingRow][index]);count++;
            }startingRow++;
            }
            if(count<total){
                for(int index=startingRow; index<=endingRow; index++){
                ans.push_back(matrix[index][endingCol]);count++;
            }endingCol--;
            }
            if(count<total){
                for(int index=endingCol; index>=startingCol; index--){
                ans.push_back(matrix[endingRow][index]);count++;
            }endingRow--;
            }
            if(count<total){
               for(int index=endingRow; index>=startingRow; index--){
                ans.push_back(matrix[index][startingCol]);count++;
            }startingCol++; 
            }  
        }
    return ans;
    }
};