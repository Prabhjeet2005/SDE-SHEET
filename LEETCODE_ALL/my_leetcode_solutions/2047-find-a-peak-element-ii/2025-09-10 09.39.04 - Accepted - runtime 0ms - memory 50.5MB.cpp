class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int start = 0, end = mat[0].size();
    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      auto maxi = INT_MIN, maxi_index = -1;
      for (int i = 0; i < mat.size(); i++)
      {
        if (mat[i][mid] > maxi)
        {
          maxi = mat[i][mid];
          maxi_index = i;
        }
      }
      int leftElement = mid - 1 < 0 ? -1 : mat[maxi_index][mid-1];
      int rightElement = mid + 1 >= mat[0].size() ? -1 : mat[maxi_index][mid+1];
      bool leftGreater = leftElement < mat[maxi_index][mid];
      bool rightGreater = mat[maxi_index][mid] > rightElement;
      if (leftGreater && rightGreater)
      {
        
        return {maxi_index,mid};
      }
      else if(leftElement < mat[maxi_index][mid] && mat[maxi_index][mid] < rightElement){
        start = mid+1;
      }else{
        end = mid-1;
      }
    }
    return {-1,-1};
    }
};