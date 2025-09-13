#include <bits/stdc++.h>
using namespace std;

bool isNodeFound(int node, int val, vector<int> adj_list[])
{
    for (int chld : adj_list[node])
        if (chld == val)
            return true;

    return false;
}

int main()
{
    int A, B;
    cin >> A >> B;

    int n1, n2;
    vector<int> adj_list[A];

    for (int i = 1; i <= B; i++)
    {
        cin >> n1 >> n2;
        adj_list[n1].push_back(n2);
    }

    int Q;
    cin >> Q;
    while (Q--)
    {
        cin >> n1 >> n2;

        if (n1 == n2 || isNodeFound(n1, n2, adj_list))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
