#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

long long dis[1005];

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> EdgeList;

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }

    for (int i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
    }

    int s;
    cin >> s;
    dis[s] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;
            if (dis[u] != LLONG_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    for (Edge ed : EdgeList)
    {
        int u = ed.u;
        int v = ed.v;
        int c = ed.c;
        if (dis[u] != LLONG_MAX && dis[u] + c < dis[v])
        {
            cout << "Negative Cycle Detected" << endl;
            return 0;
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;
        if (dis[d] == LLONG_MAX)
        {
            cout << "Not Possible" << endl;
        }
        else
        {
            cout << dis[d] << endl;
        }
    }

    return 0;
}