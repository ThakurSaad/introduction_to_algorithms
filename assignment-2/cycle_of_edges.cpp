#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int groupSize[N];

void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        groupSize[i] = 1;
    }
}

int findLeader(int node)
{
    if (parent[node] == -1)
        return node;

    int leader = findLeader(parent[node]);
    parent[node] = leader;
    return leader;
}

void UnionBySize(int node1, int node2)
{
    int leaderA = findLeader(node1);
    int leaderB = findLeader(node2);

    if (groupSize[leaderA] > groupSize[leaderB])
    {
        parent[leaderB] = leaderA;
        groupSize[leaderA] += groupSize[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        groupSize[leaderB] += groupSize[leaderA];
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

        int leaderA = findLeader(a);
        int leaderB = findLeader(b);

        if (leaderA == leaderB)
        {
            cycle++;
        }
        else
        {
            UnionBySize(a, b);
        }
    }

    cout << cycle;

    return 0;
}