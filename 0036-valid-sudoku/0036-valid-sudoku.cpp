class Solution
{
    public:
        bool isValidSudoku(vector<vector < char>> &board)
        {
            map<char, bool> cols[9], rows[9];
            map<char, bool> box[3][3];
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (board[i][j] != '.')
                    {
                        char c = board[i][j];
                        if (cols[j][c] || rows[i][c] || box[i / 3][j / 3][c])
                        {
                            return false;
                        }
                        cols[j][c] = true;
                        rows[i][c] = true;
                        box[i / 3][j / 3][c] = true;
                    }
                }
            }
            return true;
        }
};