class Solution {
public:
    int maxArea(vector<int>& height) {
        // Formula: minHeight * (rightIndex - leftIndex)
        int maxArea = -1;
        int start = 0 ,end = height.size()-1;

        while(start < end){
            int currentArea = min(height[start],height[end]) * (end - start);
            maxArea = max(maxArea,currentArea);
            if(height[start] < height[end] ){
                start++;
            }else{
                end--;
            }
        }
        return maxArea;
    }
};