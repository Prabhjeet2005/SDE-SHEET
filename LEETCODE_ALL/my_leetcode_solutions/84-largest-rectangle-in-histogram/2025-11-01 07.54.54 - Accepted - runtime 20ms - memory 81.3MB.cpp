class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);// to calculate all remaining heights left in the stack
        stack<int>stack;
        int max_area = 0;

        for(int i=0; i<heights.size(); i++){
            // current_height < actual_height_to_calculate
            while(!stack.empty() && heights[i] < heights[stack.top()]){
                int actual_height = heights[stack.top()];
                stack.pop();
                int right_boundary_index = i;
                int left_boundary_index = stack.empty() ? -1 : stack.top() ;
                // area = height * width
                int current_area = actual_height * (right_boundary_index - left_boundary_index - 1);
                max_area = max(max_area,current_area);
            }
            stack.push(i); // wait for current height to get its right boundary
        }
        return max_area;
    }
};