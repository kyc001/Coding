#include <bits/stdc++.h>
#define MAX_N 3000010
#define MAX_C 30000010
using namespace std;

struct P
{
    int x, y, id;
} A[MAX_N];
struct Q
{
    int a, b, c;
} C[MAX_C];
int T[MAX_N], pos[MAX_N], ha[MAX_N], h, cnt = 0;
int p[MAX_N];

int cmp(P a, P b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int cmp1(Q a, Q b)
{
    return a.c > b.c;
}

int id(int x, int h)
{
    int *it = lower_bound(ha + 1, ha + 1 + h, x);
    return it - ha;
}

void add(int x, int v, int k, int n)
{
    for (; x <= n; x += x & -x)
    {
        if (T[x] < v)
        {
            T[x] = v;
            pos[x] = k;
        }
    }
}

int qmax(int x, int n)
{
    int ans = 0, ma = -2000000009;
    for (; x; x -= x & -x)
    {
        if (ma < T[x])
        {
            ma = T[x];
            ans = pos[x];
        }
    }
    return ans;
}

void build(int n)
{
    int i, j, k, x;
    for (j = 1; j <= 8; j++)
    {
        for (i = 1; i <= n; i++)
        {
            if (j % 2 == 0)
                swap(A[i].x, A[i].y);
            else
                A[i].x *= -1;
        }

        sort(A + 1, A + 1 + n, cmp);
        for (i = 1; i <= n; i++)
            ha[i] = A[i].x - A[i].y;
        sort(ha + 1, ha + 1 + n);
        h = unique(ha + 1, ha + 1 + n) - ha - 1;

        for (i = 0; i <= n; i++)
        {
            T[i] = -2000000009;
            pos[i] = 0;
        }

        for (i = n; i; i--)
        {
            k = id(A[i].x - A[i].y, h);
            x = qmax(k, n);
            if (x)
            {
                C[++cnt].a = A[i].id;
                C[cnt].b = A[x].id;
                C[cnt].c = abs(A[x].x - A[i].x) + abs(A[x].y - A[i].y);
            }
            add(k, A[i].x + A[i].y, i, n);
        }
    }
}

int f(int x)
{
    if (x == p[x])
        return x;
    p[x] = f(p[x]);
    return p[x];
}

int main()
{
    int a, b, i, n;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d%d", &A[i].x, &A[i].y);
        A[i].id = p[i] = i;
    }
    build(n);
    sort(C + 1, C + 1 + cnt, cmp1);

    int ans = 0;
    for (i = 1; i <= cnt; i++)
    {
        a = f(C[i].a);
        b = f(C[i].b);
        if (a != b)
        {
            p[a] = b;
            ans = C[i].c;
        }
    }
    printf("%d\n", ans);
    return 0;
}