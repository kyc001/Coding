#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> candies(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> candies[i];
    }

    vector<int> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        prefix_sum[i] = prefix_sum[i - 1] + candies[i - 1];
    }

    int total_sum = prefix_sum[n];
    int min_diff = INT_MAX;

    for (int i = 0; i <= n; ++i)
    {
        int alice_sum = prefix_sum[i];
        int bob_sum = total_sum - alice_sum;
        int diff = abs(alice_sum - bob_sum);
        min_diff = min(min_diff, diff);
    }

    cout << min_diff << endl;

    return 0;
}