class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
         int n = nums.size();
         vector<int> res(n, -1);
         stack<int> s;

         for(int i = 0; i < 2 * n; i++) {
            while(!s.empty() && nums[i%n] > nums[s.top()]) {
                res[s.top()] = nums[i%n];
                s.pop();
            }
            if(i < n) s.push(i);
         }

         return res;
    }
};