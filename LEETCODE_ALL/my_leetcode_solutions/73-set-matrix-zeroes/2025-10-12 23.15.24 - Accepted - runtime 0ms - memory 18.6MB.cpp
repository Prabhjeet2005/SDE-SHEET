class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row0 = false, col0 = false;
        for (int col = 0; col < matrix[0].size(); col++) {
            if (matrix[0][col] == 0){
                row0 = true;
                break;
            }
        }
        for (int row = 0; row < matrix.size(); row++) {
            if (matrix[row][0] == 0){
                col0 = true;
                break;
            }
        }

        for(int row = 1; row<matrix.size();row++){
            for(int col = 1; col<matrix[0].size();col++){
                if(matrix[row][col] == 0){
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }

        for(int i=1;i<matrix.size();i++){
            for(int j=1; j<matrix[0].size();j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }

        if(row0){
            for(int i=0;i<matrix[0].size();i++){
                matrix[0][i] = 0;
            }
        }
        if(col0){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0] = 0;
            }
        }

        
    }
};