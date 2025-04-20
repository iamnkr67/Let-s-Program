class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> index;
        int maxL = 0;
        int start = 0;

        for(int i = 0; i < s.length(); ++i) {
            if(index.find(s[i]) != index.end()) {
                start = max(index[s[i]] + 1, start);
            }

            index[s[i]] = i;
            maxL = max(maxL, i - start + 1);
        }
        return maxL;
    }
};