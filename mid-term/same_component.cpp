#include <bits/stdc++.h>
using namespace std;

char a[1000][1000];
bool vis[1000][1000];

vector<pair<int, int>> d = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}};
int n, m;

bool isvalid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (
            isvalid(ci, cj) && !vis[ci][cj] && a[ci][cj] == '.')
            dfs(ci, cj);
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int si, sj;
    int di, dj;

    cin >> si >> sj;
    cin >> di >> dj;

    memset(vis, false, sizeof(vis));

    if (
        a[si][sj] == '-' || a[di][dj] == '-')
    {
        cout << "NO";
        return 0;
    }

    dfs(si, sj);

    vis[di][dj] ? cout << "YES"
                : cout << "NO";

    return 0;
}
