//Approach 1

class Solution {
public:
    void markRow(vector<vector<int>>& matrix, int n, int m, int i) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -999;
            }
        }
    }

    void markCol(vector<vector<int>>& matrix, int n, int m, int j) {
        for (int i = 0; i < n; i++) {  
            if (matrix[i][j] != 0) {
                matrix[i][j] = -999;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();     // rows
        int m = matrix[0].size();  // columns

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    markRow(matrix, n, m, i);
                    markCol(matrix, n, m, j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == -999) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Approach 2

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n=matrix.size(),m=matrix[0].size();

        bool rowv=0,colv=0;
        for(int i=0;i<m;i++){
            if(matrix[0][i]==0){
                rowv=1;
                break;
            }
        }
         for(int i=0;i<n;i++){
            if(matrix[i][0]==0){
                colv=1;
                break;
            }
        }
          
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                 matrix[0][j]=0;
                 matrix[i][0]=0;
                }
            }
        }

         for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[0][j]==0||matrix[i][0]==0)
                {
                 matrix[i][j]=0;
                }
            }
        }
       
         if(colv)
        {
            for(int j=0;j<n;j++){
                matrix[j][0]=0;
            }
        }
        if(rowv)
        {
            for(int j=0;j<m;j++){
                matrix[0][j]=0;
            }
        }
        

    }


};
