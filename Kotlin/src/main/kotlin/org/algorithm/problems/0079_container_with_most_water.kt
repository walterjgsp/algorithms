// Problem Statement
// Given n non-negative integers a1, a2, ..., an , where each represents a point at
// coordinate (i, ai). n vertical lines are drawn such that the two endpoints of
// line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
// forms a container, such that the container contains the most water.
//
// Note: You may not slant the container and n is at least 2.
import java.lang.Math;

class Solution {
    fun maxArea(height: IntArray): Int {
        var start = 0;
        var end = height.size-1;
        var maxArea = 0;
        var area :Int;

        while(start<end){
            area = Math.min(height[start],height[end])*(end-start);
            maxArea = Math.max(maxArea,area);

            if(height[start]>height[end]){
                end--;
            }else{
                start++;
            }
        }

        return maxArea;
    }
}

fun main(args:Array<String>){
  val heights = intArrayOf(1,8,6,2,5,4,8,3,7);
  val sol = Solution();
  println(sol.maxArea(heights));
}
