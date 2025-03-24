class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        merged.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i) {
            vector<int>& lastInterval = merged.back();

            if(intervals[i][0] <= lastInterval[1]) {
                lastInterval[1] = max(lastInterval[1], intervals[i][1]);
            } else {
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};