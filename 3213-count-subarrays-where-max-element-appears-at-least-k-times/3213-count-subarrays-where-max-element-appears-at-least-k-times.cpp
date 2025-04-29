class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxElem = *max_element(nums.begin(), nums.end());
        long long res = 0;
        int count = 0;
        int l = 0;

        for(int r = 0; r < n; ++r) {
            if(nums[r] == maxElem) count++;

            while(count >= k) {
                res += (n-r);
                if(nums[l] == maxElem) count--;
                l++;
            }
        }
        return res;
    }
};