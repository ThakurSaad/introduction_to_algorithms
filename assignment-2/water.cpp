#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> h(n);

        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }

        int maxV = -1, secondMaxV = -1;
        int maxIdx = -1, secondMaxIdx = -1;

        for (int i = 0; i < n; i++)
        {
            if (h[i] > maxV)
            {
                secondMaxV = maxV;
                secondMaxIdx = maxIdx;
                maxV = h[i];
                maxIdx = i;
            }
            else if (h[i] > secondMaxV)
            {
                secondMaxV = h[i];
                secondMaxIdx = i;
            }
        }

        if (maxIdx < secondMaxIdx)
            cout << maxIdx << " " << secondMaxIdx << endl;
        else
            cout << secondMaxIdx << " " << maxIdx << endl;
    }

    return 0;
}