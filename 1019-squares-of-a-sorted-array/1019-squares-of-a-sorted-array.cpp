class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i<n; i++) {
            nums[i] = nums[i]*nums[i];
        }
        int l = 0, r = n-1;
        vector<int> ans(n, 0);

        for(int i = r; i >= 0; --i ) {
            if(nums[l] >= nums[r]) {
                ans[i] = nums[l];
                l++;
            } else {
                ans[i] = nums[r];
                r--;
            }
        }
        return ans;
    }
};