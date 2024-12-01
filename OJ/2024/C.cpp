#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int maxVal = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        maxVal = max(maxVal, a[i]);
    }

    int ans = 0;
    vector<int> count(maxVal + 1, 0);
    int mexVal = 0;
    int l = 0;

    for (int r = 0; r < n; ++r)
    {
        count[a[r]]++;
        while (mexVal <= maxVal && count[mexVal] > 0)
        {
            mexVal++;
        }
        while (mexVal >= x)
        {
            ans += n - r;
            count[a[l]]--;
            if (count[a[l]] == 0 && a[l] < mexVal)
            {
                mexVal = a[l];
                while (mexVal > 0 && count[mexVal - 1] == 0)
                {
                    mexVal--;
                }
            }
            l++;
        }
    }

    cout << ans << endl;
    return 0;
}
/*
    5 2
    2 0 1 1 0
*/