class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mJump = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(i > mJump) 
               return false;
            mJump = max(mJump,i + nums[i]);

            if(mJump >= n-1) return true;
        }
        return false;
    }
};