class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> sum;
        for(int i = 0; i<nums.size(); i++) {
            int rem = target - nums[i];
            if(sum.find(rem) != sum.end()) return {sum[rem], i};
            sum[nums[i]] = i;
        }
        return {};
    }
};