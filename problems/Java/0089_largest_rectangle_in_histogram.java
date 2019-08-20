import java.util.Stack;

class Main{
    public static void main(String[] args) {
        Solution sol = new Solution();
        int histogram[] = {2,1,5,6,2,3};
        System.out.println(sol.largestRectangleArea(histogram));
    }
}

class Solution {
    public int largestRectangleArea(int[] heights) {

        Stack<Integer> indices = new Stack<Integer>();
        int result = 0;

        for(int i=0;i<heights.length;i++){
            while(!indices.isEmpty() && heights[indices.peek()]>=heights[i]){
                int currHeight = heights[indices.peek()];
                indices.pop();
                int area = 0;

                if(indices.isEmpty()){
                    area = currHeight * i;
                }else{
                    area = currHeight * (i-indices.peek()-1);
                }

                result = Math.max(area, result);
            }
            indices.push(i);
        }

        while(!indices.isEmpty()){
            int currHeight = heights[indices.peek()];
            indices.pop();

            int area = 0;

            if(indices.isEmpty()){
                area = currHeight * heights.length;
            }else{
                area = currHeight * (heights.length-indices.peek()-1);
            }

            result = Math.max(area, result);
        }

        return result;
    }
}