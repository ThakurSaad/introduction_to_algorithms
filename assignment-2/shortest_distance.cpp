#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll INF = 1e18;

int main()
{
    ll n, e;
    cin >> n >> e;

    ll adj[n + 1][n + 1];
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
        adj[a][b] = min(adj[a][b], (ll)c);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj[i][k] != INF && adj[k][j] != INF)
                {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
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