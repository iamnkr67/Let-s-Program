class Solution {
public:
    static bool comp(const pair<char, int>&a, pair<char, int>&b) {
        return a.second > b.second;
    }
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(auto i : s) {
            m[i]++;
        }
       vector<pair<char, int>> v(m.begin(), m.end());
       sort(v.begin(), v.end(), comp);
        string ans;
        for(const auto& i : v) {
            ans.append(i.second, i.first);
        }
        return ans;
    }
};