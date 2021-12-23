



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return;
        int n = matrix[0].size();
        vector<bool> row(m), col(n);
        for (int i = 0; i < m;i++){
            for (int j = 0; j < n;j++){
                if(matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                };
            }
        }
        for (int i = 0; i < m;i++){
            for (int j = 0; j < n;j++){
                if(row[i] || j[j]){
                    matrix[i][j] = 0;
                };
            }
        }
        return;
    }
};










