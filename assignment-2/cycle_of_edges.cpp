#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int groupSz[N];

void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        groupSz[i] = 1;
    }
}

int find_leader(int node)
{
    if (parent[node] == -1)
        return node;

    int leader = find_leader(parent[node]);
    parent[node] = leader;
    return leader;
}

void union_by_size(int node1, int node2)
{
    int leaderA = find_leader(node1);
    int leaderB = find_leader(node2);

    if (groupSz[leaderA] > groupSz[leaderB])
    {
        parent[leaderB] = leaderA;
        groupSz[leaderA] += groupSz[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        groupSz[leaderB] += groupSz[leaderA];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    dsu_initialize(n);

    int cycle = 0;

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = find_leader(a);
        int leaderB = find_leader(b);

        if (leaderA == leaderB)
        {
            cycle++;
        }
        else
        {
            union_by_size(a, b);
        }
    }

    cout << cycle;

    return 0;
}