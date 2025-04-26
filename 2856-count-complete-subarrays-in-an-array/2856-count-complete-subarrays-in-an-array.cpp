class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
         unordered_map<int, int> mp;
         for(int i : nums) mp[i]++;

         int uEl = mp.size();

         int i{}, j{};
         int count = 0;
         unordered_map<int, int> fmp;
         while(j < nums.size()) {
            fmp[nums[j]]++;
            if(fmp.size() == uEl) {
                count += nums.size() - j;
                while(fmp.size() == uEl){
                    fmp[nums[i]]--;
                    if(fmp[nums[i]] == 0) fmp.erase(nums[i]);
                    i++;
                    if(fmp.size() == uEl) count += nums.size() - j;
                }
            }
            j++;
         }
         return count;
    }
};