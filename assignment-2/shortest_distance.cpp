#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main()
{
    long long n, e;
    cin >> n >> e;

    long long adj[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adj[i][j] = INF;
            if (i == j)
                adj[i][j] = 0;
        }
    }

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], (long long)c);
    }

    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            for (int z = 1; z <= n; z++)
            {
                if (adj[y][x] != INF && adj[x][z] != INF)
                {
                    adj[y][z] = min(adj[y][z], adj[y][x] + adj[x][z]);
                }
            }
        }
    }

    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        if (adj[a][b] == INF)
            cout << -1 << endl;
        else
            cout << adj[a][b] << endl;
    }

    return 0;
}