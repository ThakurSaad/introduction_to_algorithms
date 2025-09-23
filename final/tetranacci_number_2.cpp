#include <bits/stdc++.h>
using namespace std;

long long int tetranacci_sequence(int n)
{
    if (n == 0 || n == 1)
        return n;

    if (n == 2)
        return 1;

    if (n == 3)
        return 2;

    long long int a = 0,
                  b = 1,
                  c = 1,
                  d = 2;
    long long int result = 0;

    int i = 4;
    while (i <= n)
    {
        result = a + b + c + d;
        a = b;
        b = c;
        c = d;
        d = result;
        i++;
    }

    return d;
}

int main()
{
    int n;
    cin >> n;

    cout << tetranacci_sequence(n);

    return 0;
}