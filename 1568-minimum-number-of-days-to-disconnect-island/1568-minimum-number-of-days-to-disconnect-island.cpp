class Solution
{
    public:
        int dx[4] = { -1,
            1,
            0,
            0
        };
    int dy[4] = { 0,
        0,
        -1,
        1
    };
    int vis[30][30];
    int n, m;
    void dfs(int r, int c, vector<vector < int>> &grid)
    {
       	// cout<<vis[r][c]<<" ";
        if (r < 0 || r >= n || c < 0 || c >= m || vis[r][c] || grid[r][c] == 0) return;
        vis[r][c] = 1;
       	// cout<<"HELLO WORLD\n";
       	// cout<<r<<" "<<c<<endl;
        for (int i = 0; i < 4; i++)
        {
            int X = dx[i] + r;
            int Y = dy[i] + c;
            dfs(X, Y, grid);
        }
    }
    int dfs_x(vector<vector < int>> &grid)
    {
        memset(vis, 0, sizeof(vis));
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
    int lv[100];
    int bfs(vector<vector < int>> &grid)
    {
        memset(vis, 0, sizeof(vis));

        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        int l = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    cnt++;
                    queue<pair<int, int>> q;
                    q.push({ i,
                        j });
                    vis[i][j] = 1;

                    while (q.size())
                    {
                        int ns = q.size();
                        lv[l] = ns;
                        while (ns--)
                        {
                            pair<int, int> d = q.front();
                            q.pop();
                            int x = d.first;
                            int y = d.second;
                            for (int k = 0; k < 4; k++)
                            {
                                int X = dx[k] + x;
                                int Y = dy[k] + y;
                                if (X < 0 || X >= n || Y < 0 || Y >= m || vis[X][Y] || grid[X][Y] == 0) continue;
                                vis[X][Y] = 1;
                                q.push({ X,
                                    Y });
                            }
                        }
                        l++;
                    }
                }
            }
        }

        if (l <= 2)
        {
            return lv[0] + lv[1];
        }
       	// cout<<l<<endl;
        int ans = INT_MAX;
        for (int i = 1; i < (l - 1); i++)
        {
           	// cout<<lv[i]<<" ";
            ans = min(ans, lv[i]);
        }
       	// cout<<endl;
        return ans;
    }
    int minDays(vector<vector < int>> &grid)
    {

        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((grid[i][j] == 1) && !vis[i][j])
                {
                   	// cout<<i<<" "<<j<<endl;
                    dfs(i, j, grid);
                    cnt++;
                }
                // cout << endl;
            }
        }
        // cout << cnt << endl;
        if (cnt > 1) return 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {

                    grid[i][j] = 0;
                    int l = dfs_x(grid);
                   	// cout<<l<<endl;
                    if (l > 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return bfs(grid);
    }
};