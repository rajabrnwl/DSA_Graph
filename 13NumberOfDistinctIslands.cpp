void dfs(int n, int m, int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &vec, int r0, int c0)
{
    vis[r][c] = 1;
    vec.push_back({r - r0, c - c0});
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, -1, 0, 1};
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && vis[nr][nc] == 0)
        {
            dfs(n, m, nr, nc, grid, vis, vec, r0, c0);
        }
    }
}
int countDistinctIslands(vector<vector<int>> &grid)
{
    // code here
    int n = grid.size();
    int m = grid[0].size();
    set<vector<pair<int, int>>> s;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
            {
                vector<pair<int, int>> vec;
                dfs(n, m, i, j, grid, vis, vec, i, j);
                s.insert(vec);
            }
        }
    }
    return s.size();
}