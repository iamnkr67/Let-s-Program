class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;

        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        if(minVal == maxVal) return 0;

        int bucketSize = max(1, (maxVal-minVal)/ (n-1));
        int bucketCount = (maxVal - minVal) / bucketSize + 1;

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);
        vector<int> bucketUsed(bucketCount, false);

        for(int num : nums) {
            int idx = (num - minVal) / bucketSize;
            bucketMin[idx] = min(bucketMin[idx], num);
            bucketMax[idx] = max(bucketMax[idx], num);
            bucketUsed[idx] = true;
        }

        int maxGap  = 0;
        int prevMax = minVal;

        for(int i = 0; i<bucketCount; ++i) {
            if(!bucketUsed[i]) continue;
            maxGap = max(maxGap, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }

        return maxGap;
    }
};


// Finding min and max : O(n)
// Placing elements into buckets: O(n)
// Scanning through buckets: O(n)
// Total: O(n)

// SC: O(n)