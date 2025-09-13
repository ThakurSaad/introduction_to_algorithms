#include <bits/stdc++.h>
using namespace std;

int calcMinSteps(int n, int m, int kx, int ky, int qx, int qy)
{
    if (kx == qx && ky == qy)
        return 0;

    bool vis[100][100] = {false};

    vector<pair<int, int>> dir = {

        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}}; // just like straight line math.

    queue<pair<pair<int, int>, int>> q;
    q.push({{kx, ky}, 0});
    vis[kx][ky] = true;

    while (!q.empty())
    {
        pair<pair<int, int>, int> current = q.front();
        q.pop();

        int x = current.first.first;
        int y = current.first.second;
        int steps = current.second;

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny])
            {
                if (nx == qx && ny == qy)
                    return steps + 1;

                vis[nx][ny] = true;
                q.push({{nx, ny}, steps + 1});
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, kx, ky, qx, qy;
        cin >> n >> m;
        cin >> kx >> ky;
        cin >> qx >> qy;

        cout << calcMinSteps(n, m, kx, ky, qx, qy) << endl;
    }
}
