class NumMatrix
{
    public:
        vector<vector < int>> res;
    NumMatrix(vector<vector < int>> &matrix)
    {
        res = matrix;
        int n = res.size();
        int m = res[0].size();
        for (int i = 1; i < n; i++)
        {
            res[i][0] += res[i - 1][0];
        }
        for (int i = 1; i < m; i++)
        {
            res[0][i] += res[0][i - 1];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {

                int right = res[i - 1][j];
                int left = res[i][j - 1];
                int rl = res[i - 1][j - 1];
                res[i][j] += right + left - rl;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {

        int toth = res[row2][col2];
        int right = (row1 > 0 ? res[row1 - 1][col2] : 0);
        int left = (col1 > 0 ? res[row2][col1 - 1] : 0);
        int rl = 0;
        if (row1 > 0 && col1 > 0) rl = res[row1 - 1][col1 - 1];
        return (toth - right - left + rl);
    }
};

/**
 *Your NumMatrix object will be instantiated and called as such:
 *NumMatrix* obj = new NumMatrix(matrix);
 *int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */