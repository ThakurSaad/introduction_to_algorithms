#include <bits/stdc++.h>
using namespace std;

vector<int> near_node_finder(int node, vector<int> adj_list[])
{
    vector<int> v;

    for (int chld : adj_list[node])
        v.push_back(chld);

    sort(v.rbegin(), v.rend());

    return v;
}

int main()
{
    int x, y;
    cin >> x >> y;

    vector<int> adj_list[x];
    int n1, n2;

    for (int i = 0; i < y; i++)
    {
        cin >> n1 >> n2;
        adj_list[n1].push_back(n2);
        adj_list[n2].push_back(n1);
    }

    int q;
    cin >> q;
    while (q--)
    {
        cin >> n1;
        vector<int> v;
        v = near_node_finder(n1, adj_list);

        if (v.size() > 0)
            for (int val : v)
                cout << val << " ";
        else
            cout << -1 << " ";

        cout << endl;
    }

    return 0;
}
