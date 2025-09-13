#include <bits/stdc++.h>
using namespace std;

char a[1001][1001];
bool vis[1001][1001];

vector<pair<int, int>> d = {
    {0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int n, m;

bool isValid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;

    if (a[i][j] == '#')
        return false;

    return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int k = 0; k < 4; k++)
    {
        int ci = si + d[k].first;
        int cj = sj + d[k].second;
        if (isValid(ci, cj) && !vis[ci][cj])
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> m;
    int si, sj, ei, ej;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (a[i][j] == 'B')
            {
                ei = i;
                ej = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    dfs(si, sj);

    if (vis[ei][ej])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
