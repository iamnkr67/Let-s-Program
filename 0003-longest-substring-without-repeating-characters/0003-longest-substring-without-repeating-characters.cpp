class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int i = 0, j = 0;
        int maxLen = 0;
        while(j < s.length()){
          if(mp.find(s[j]) != mp.end() && i <= mp[s[j]]+1 ){
            i = mp[s[j]]+1;
          }
          maxLen = max(maxLen,j-i+1);
          mp[s[j]] = j;
          j++;
        }
        return maxLen;
    }
}; 