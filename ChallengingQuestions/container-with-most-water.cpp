// 11. Container With Most Water {Medium Level} on LeetCode
class Solution {
public:
    int maxArea(vector<int>& height) {
      int left{}, right = height.size() - 1;
      int maxArea{};

      while(left < right) {
        int cArea = min(height[left], height[right]) * (right - left);
        maxArea = max(maxArea, cArea);

        if(height[left] < height[right])
           left++;
        else 
           right--;
      } 
      return maxArea;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
