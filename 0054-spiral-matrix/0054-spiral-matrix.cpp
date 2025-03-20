class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int m = matrix.size(); // rows
        int n = matrix[0].size(); // columns

        int top = 0, btm = m - 1, l = 0, r = n - 1;

        while(top <= btm && l <= r) {
            for(int i = l; i<=r; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;

            for(int i = top; i<=btm; i++) {
                res.push_back(matrix[i][r]);
            }
            r--;

            if(top <= btm) {
                for(int i = r; i >= l; i--) {
                    res.push_back(matrix[btm][i]);
                }
                btm--;
            }

            if(l <= r ) {
                for(int i = btm; i >= top; i--) {
                    res.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return res;
    }
};