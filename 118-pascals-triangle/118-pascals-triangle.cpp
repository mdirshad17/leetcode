class Solution
{
    public:
        vector<vector < int>> generate(int numRows)
        {
            int n = numRows;
            vector<vector < int>> res;
            for (int i = 0; i < n; i++)
            {
                vector<int> ptr;
                for (int j = 0; j <= i; j++)
                {
                    if (j == 0 || j == i) ptr.push_back(1);
                    else
                    {
                        ptr.push_back((res[i - 1][j] + res[i - 1][j - 1]));
                    }
                }
                res.push_back(ptr);
            }
            return res;
        }
};