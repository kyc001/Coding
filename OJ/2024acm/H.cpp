#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

struct Edge
{
    int to, dis;
};

vector<Edge> graph[MAXN];
vector<pair<int, int>> students;
int N, K;

bool check(int mid, int start)
{
    vector<int> dist(N + 1, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (d > dist[cur])
            continue;
        for (const Edge &e : graph[cur])
        {
            int newDist = d + e.dis;
            if (newDist < dist[e.to])
            {
                dist[e.to] = newDist;
                pq.push({newDist, e.to});
            }
        }
    }
    for (const auto &s : students)
    {
        int building = s.first;
        int speed = s.second;
        int commuteTime = dist[building] * speed;
        if (commuteTime > mid)
            return false;
    }
    return true;
}

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b, dis;
        cin >> a >> b >> dis;
        graph[a].push_back({b, dis});
        graph[b].push_back({a, dis});
    }
    for (int i = 0; i < K; ++i)
    {
        int building, speed;
        cin >> building >> speed;
        students.push_back({building, speed});
    }
    int left = 0, right = INF;
    int ans = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        bool found = false;
        for (int i = 1; i <= N; ++i)
        {
            if (check(mid, i))
            {
                ans = i;
                found = true;
                break;
            }
        }
        if (found)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
