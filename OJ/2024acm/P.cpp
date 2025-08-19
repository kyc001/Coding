#include <bits/stdc++.h>
using namespace std;

// 计算最小关卡数和最大难度指数
pair<int, int> solve(int s, int d, vector<int> &x_list)
{
    vector<int> dp(s + 1, INT_MAX);
    dp[0] = 0;
    int d_max = 0;
    for (int i = 1; i <= s; ++i)
    {
        int x = x_list[i - 1];
        x -= d;
        if (x < 0)
        {
            dp[i] = -1;
        }
        else if (x == 0)
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            for (int j = max(0, i - (x + 1)); j < i; ++j)
            {
                if (dp[j] != -1 && dp[i] > dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        // 重新计算d_max
        if (dp[i] != -1)
        {
            int temp_d_max = 0;
            int cur_d = 0;
            int cur_i = i;
            while (cur_i > 0 && cur_d <= d)
            {
                cur_i = max(cur_i - (x_list[cur_i - 1] - cur_d), 0);
                temp_d_max += max(x_list[cur_i - 1] - cur_d, 0);
                cur_d += d;
            }
            d_max = max(d_max, temp_d_max);
        }
    }
    if (dp[s] == INT_MAX)
    {
        return {-1, d_max};
    }
    return {dp[s], d_max};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int s, d;
        cin >> s >> d;
        vector<int> x_list(s);
        for (int i = 0; i < s; ++i)
        {
            cin >> x_list[i];
        }
        pair<int, int> result = solve(s, d, x_list);
        cout << result.first << " " << result.second << endl;
    }
    return 0;
}