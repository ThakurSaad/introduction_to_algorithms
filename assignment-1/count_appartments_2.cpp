#include <bits/stdc++.h>
using namespace std;

int n, m;
char grd[1005][1005];
bool vis[1005][1005];

vector<pair<int, int>> d = {
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0}};

bool isValid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    if (grd[i][j] == '#')
        return false;

    return true;
}

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int count = 1;
    for (auto [dx, dy] : d)
    {
        int ci = si + dx;
        int cj = sj + dy;
        if (isValid(ci, cj) && !vis[ci][cj])
            count += dfs(ci, cj);
    }

    return count;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grd[i][j];

    memset(vis, false, sizeof(vis));
    vector<int> apartments;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grd[i][j] == '.' && !vis[i][j])
            {
                int rooms = dfs(i, j);
                apartments.push_back(rooms);
            }
        }
    }

    if (apartments.empty())
    {
        cout << "0" << endl;
        return 0;
    }

    sort(apartments.begin(), apartments.end());

    for (int i = 0; i < (int)apartments.size(); i++)
    {
        cout << apartments[i];
        if (i != apartments.size() - 1)
            cout << " ";
    }

    

    return 0;
}
