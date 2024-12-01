#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
int dp[MAXN][MAXN];
int freq[MAXN];
int prefixSum[MAXN];
int s[MAXN][MAXN]; // 记录最优分割点的区间

int sumFreq(int start, int end)
{
    return prefixSum[end] - prefixSum[start - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> freq[i];
        prefixSum[i] = prefixSum[i - 1] + freq[i];
    }

    for (int len = 1; len <= n; ++len)
    {
        for (int i = 1; i + len - 1 <= n; ++i)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            if (len == 1)
            {
                dp[i][j] = freq[i];
                s[i][j] = i;
                continue;
            }
            int kmin = s[i][j - 1];
            int kmax = (j == n ? s[i + 1][j] : min(s[i + 1][j], j));
            for (int k = kmin; k <= kmax; ++k)
            {
                int cost = (k > i ? dp[i][k - 1] : 0) + (k < j ? dp[k + 1][j] : 0) + sumFreq(i, j);
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}