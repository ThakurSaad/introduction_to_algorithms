#include <bits/stdc++.h>
using namespace std;

int n, m;
char grd[1001][1001];
bool vis[1001][1001];

vector<pair<int, int>> d = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}};

bool isValid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    if (grd[i][j] == '#')
        return false;

    return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (isValid(ci, cj) && !vis[ci][cj])
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grd[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    int apartments = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grd[i][j] == '.' && !vis[i][j])
            {
                dfs(i, j);
                apartments++;
            }
        }
    }

    cout << apartments << endl;
    return 0;
}
