#include <bits/stdc++.h>
using namespace std;

char a[1000][1000];
bool vis[1000][1000];
pair<int, int> parent[1000][1000];
vector<pair<int, int>> d = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;

bool isvalid(int i, int j)
{
    return i >= 0 && i < n;
}

void bfs(int si, int sj, int di, int dj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> currentCell = q.front();
        q.pop();

        int first = currentCell.first;
        int second = currentCell.second;

        if (first == di && second == dj)
            break;

        for (int i = 0; i < 4; i++)
        {
            int ci = first + d[i].first;
            int cj = second + d[i].second;

            if (
                isvalid(ci, cj) && !vis[ci][cj] && (a[ci][cj] == '.' || a[ci][cj] == 'D'))
            {
                vis[ci][cj] = true;
                parent[ci][cj] = {first, second};
                q.push({ci, cj});
            }
        }
    }

    int ci = di, cj = dj;
    while (parent[ci][cj].first != -1)
    {
        int pi = parent[ci][cj].first;
        int pj = parent[ci][cj].second;

        if (a[pi][pj] == '.')
            a[pi][pj] = 'X';

        ci = pi;
        cj = pj;
    }
}

int main()
{
    cin >> n >> m;
    int si = -1, sj = -1, di = -1, dj = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            parent[i][j] = {-1, -1};
            if (a[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (a[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    bfs(si, sj, di, dj);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j];

        cout << endl;
    }
}
