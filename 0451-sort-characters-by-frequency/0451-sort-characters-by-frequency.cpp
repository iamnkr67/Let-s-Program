class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(auto i : s) {
            m[i]++;
        }
        vector<pair<char, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](const pair<char, int>& a, const pair<char, int>&b)   {return a.second > b.second;});
        string ans;
        for(const auto& i : v) {
            ans.append(i.second, i.first);
        }
        return ans;
    }
};