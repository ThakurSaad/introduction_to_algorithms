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
        vector<int> heights(n);

        for (int i = 0; i < n; i++)
        {
            cin >> heights[i];
        }

        int maxVal = -1, secondMaxVal = -1;
        int maxIdx = -1, secondMaxIdx = -1;

        for (int i = 0; i < n; i++)
        {
            if (heights[i] > maxVal)
            {
                secondMaxVal = maxVal;
                secondMaxIdx = maxIdx;
                maxVal = heights[i];
                maxIdx = i;
            }
            else if (heights[i] > secondMaxVal)
            {
                secondMaxVal = heights[i];
                secondMaxIdx = i;
            }
        }

        if (maxIdx < secondMaxIdx)
        {
            cout << maxIdx << " " << secondMaxIdx << endl;
        }
        else
        {
            cout << secondMaxIdx << " " << maxIdx << endl;
        }
    }

    return 0;
}