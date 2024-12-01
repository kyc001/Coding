#include <bits/stdc++.h>
using namespace std;

int ans, temp, res = -1;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first > b.first;
    else
        return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> videos(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> videos[i].first >> videos[i].second;
    }
    sort(videos.begin(), videos.end(), cmp);
    // for (int i = 0; i < n; ++ i) {
    //     cout << videos[i].first << " " << videos[i].second << endl;
    // }
    for (int i = 0; i < n; ++i)
    {
        if (temp < videos[i].second)
        {
            temp = videos[i].second;
            ans += videos[i].first;
        }
        else {
            res = max(res, videos[i].first);
            continue;
        }
    }
    if(res != -1) {
        ans = ans + res;
    }
    cout << ans << endl;
    return 0;
}