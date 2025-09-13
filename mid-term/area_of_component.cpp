#include <bits/stdc++.h>
using namespace std;

char a[1001][1001];
bool vis[1001][1001];
vector<pair<int, int>> d = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;
int minimum = INT_MAX;

bool isvalid(int i, int j)
{
    return (i >= 0 && i < n);
}

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int cnt = 1;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (
            isvalid(ci, cj) && !vis[ci][cj] && a[ci][cj] == '.')
            cnt += dfs(ci, cj);
    }

    return cnt;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    memset(vis, false, sizeof(vis));
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && a[i][j] == '.')
            {
                int count = dfs(i, j);
                minimum = min(minimum, count);
                found = true;
            }
        }
    }

    found ? cout << minimum : cout << -1;

    return 0;
}
