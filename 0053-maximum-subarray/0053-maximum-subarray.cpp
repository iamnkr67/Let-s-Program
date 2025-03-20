class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ms = INT_MIN, sum = 0;

        for(int i : nums) {
            sum += i;
            if(sum > ms) ms = sum;
            if(sum < 0) sum = 0;
        }

        return ms;
    }
};