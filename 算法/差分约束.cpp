#include <bits/stdc++.h>

using namespace std;

// 你的风格：全局变量，常量定义
const int N = 5005;   // 节点数上限
const int M = 10005;  // 边数上限

int n, m;
int head[N], cnt;  // 邻接表头和边的计数器
int dist[N];       // 存储最短路径
int num[N];        // 记录每个点入队次数，用于判断负环
bool vis[N];       // 记录点是否在队列中

struct edge {
    int to, len, next;
} e[M];

// 你的风格：简洁的 add 函数
void add(int u, int v, int w) {
    e[++cnt] = {v, w, head[u]};
    head[u] = cnt;
}

// SPFA 算法，用于求解单源最短路并判断负环
bool spfa(int start_node) {
    // 初始化距离数组为一个“无穷大”的值，0x3f3f3f3f 是常用技巧，防止加法溢出
    memset(dist, 0x3f, sizeof(dist));
    queue<int> q;

    dist[start_node] = 0;
    q.push(start_node);
    vis[start_node] = true;
    num[start_node]++;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;  // 节点出队，标记为不在队列中

        for(int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            int len = e[i].len;

            if(dist[v] > dist[u] + len) {
                dist[v] = dist[u] + len;
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                    num[v]++;
                    // 【修正】如果一个点入队次数超过了总点数 n，说明存在负环
                    // 原代码的 == n + 1 是一个细微的bug，应为 >= n
                    // 在这个有超级源点的图中，总点数是 n+1，所以判断条件是 > n
                    if(num[v] > n) {
                        return false;  // 发现负环
                    }
                }
            }
        }
    }
    return true;  // 没有负环
}

int main() {
    // 你的风格：cin/cout 快速 IO
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // 题目通常是求差分约束 x_u - x_v <= w，建边为 v -> u，权重 w
        add(v, u, w);
    }

    // 建立一个超级源点 0，连接到所有其他点，确保图的连通性
    // 这是处理差分约束系统的一个常用技巧
    int super_source = 0;
    for(int i = 1; i <= n; i++) {
        add(super_source, i, 0);
    }

    if(!spfa(super_source)) {
        cout << "NO" << endl;
    } else {
        for(int i = 1; i <= n; i++) {
            cout << dist[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}