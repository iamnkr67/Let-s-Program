class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k){
        unordered_map<int, long long> fmp;
        fmp[0] = 1;
        long long res = 0;
        int prefix = 0;

        for(int i : nums) {
           prefix += i%modulo == k;
            int target = (prefix - k + modulo)%modulo;
            res += fmp[target];
            fmp[prefix%modulo]++;
        }

        return res;
    }
};