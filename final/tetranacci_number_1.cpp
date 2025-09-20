#include <bits/stdc++.h>
using namespace std;

int tetranacci_sequence(int n)
{
    if (n == 0 || n == 1)
        return n;

    if (n == 2)
        return 1;

    if (n == 3)
        return 2;

    int result = tetranacci_sequence(n - 1) + tetranacci_sequence(n - 2) + tetranacci_sequence(n - 3) + tetranacci_sequence(n - 4);

    return result;
}

int main()
{
    int n;
    cin >> n;

    cout << tetranacci_sequence(n);

    return 0;
}