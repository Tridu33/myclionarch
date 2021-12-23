//https://blog.nowcoder.net/n/d95c8a27b55b4e5ca23baf72a78f5cae?from=nowcoder_improve

// https://ac.nowcoder.com/acm/contest/1061/C?&headNav=acm 书P417 PKU ACM

/*
 * 链接：https://ac.nowcoder.com/acm/contest/1061/C
来源：牛客网

给定一张 N 个点 M 条边的有向无环图，点的编号从 0 到 N - 1，每条边都有一个长度。

给定一个起点 S 和一个终点 T。

若从 S 到 T 的每条路径都经过某条边，则称这条边是有向图的必经边或桥。

北大 ACM 队要从 S 点到 T 点。

他们在路上可以搭乘两次车。

每次可以从任意位置（甚至是一条边上的任意位置）上车，从任意位置下车，但连续乘坐的长度不能超过 q 米。

除去这两次乘车外，剩下的路段步行。

定义从 S 到 T 的路径的危险程度等于步行经过的桥上路段的长度之和。

求从 S 到 T 的最小危险程度是多少。

1
8 9 0 7 7
0 4 1
0 1 10
1 2 9
4 2 2
2 5 8
4 3 3
5 6 6
5 6 7
6 7 5

第一行包含整数 L，表示共有 L 组测试数据。
每组测试数据，第一行包含五个整数 N,M,S,T,q 。
接下来 M 行，每行包含三个整数u,v,w，表示点 u 到点 v 存在一条边，长度为 w。

 * */
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100005, M = 200005, P = 1e9 + 7, INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int n, m, S, T, Q;
int head[N], bhead[N], pre[N], d[N], g[N], ds[N], dt[N], degS[N];
int a[N], tot, q[N], degT[N], disS[N], disT[N], fs[N], ft[N], numE;
bool st[M << 2], bri[N];
struct E{
    int next, v, w;
} e[M << 2];
void inline add(int u, int v, int w, int h[]) {
    e[++numE] = (E) { h[u], v, w };
    h[u] = numE;
}
void toposort(int s, int t, int h[], int cnt[], int dis[], int deg[]) {
    for (int i = 0; i < n; i++) cnt[i] = 0, dis[i] = INF;
    dis[s] = 0, cnt[s] = 1;
    int hh = 0, tt = 0; q[0] = s;
    for (int i = 0; i < n; i++) if (i != s && !deg[i]) q[++tt] = i;
    while (hh <= tt) {
        int u = q[hh++];
        for (int i = h[u]; ~i; i = e[i].next) {
            int v = e[i].v;
            if (dis[u] + e[i].w < dis[v]) {
                dis[v] = dis[u] + e[i].w;
                pre[v] = i;
            }
            (cnt[v] += cnt[u]) %= P;
            if (--deg[v] == 0) q[++tt] = v;
        }
    }
}
void inline clear() {
    numE = -1, tot = 0;
    memset(head, -1, sizeof head), memset(bhead, -1, sizeof bhead);
    memset(st, false, sizeof st), memset(degS, 0, sizeof degS);
    memset(degT, 0, sizeof degT), memset(bri, false, sizeof bri);
}
int main() {
    int Case; scanf("%d", &Case);
    while (Case--) {
        clear();
        scanf("%d%d%d%d%d", &n, &m, &S, &T, &Q);
        for (int i = 1, u, v, w; i <= m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w, head); add(v, u, w, bhead);
            degS[v]++, degT[u]++;
        }
        toposort(T, S, bhead, ft, disT, degT);
        toposort(S, T, head, fs, disS, degS);
        a[++tot] = T; int p = T;
        while (a[tot] != S)
            a[tot + 1] = e[pre[a[tot]] ^ 1].v, tot++;
        reverse(a + 1, a + 1 + tot);
        for (int i = 1; i <= tot; i++) d[i] = disS[a[i]];
        for (int u = 0; u < n; u++) {
            for (int i = head[u]; ~i; i = e[i].next) {
                int v = e[i].v;
                if ((LL)fs[u] * ft[v] % P == fs[T]) st[i] = true;
            }
        }
        for (int i = 2; i <= tot; i++) bri[i] = st[pre[a[i]]], g[i] = g[i - 1] + (bri[i] ? e[pre[a[i]]].w : 0);
        int k = 1;
        for (int i = 2; i <= tot; i++) {
            ds[i] = min(g[i], ds[i - 1] + g[i] - g[i - 1]);
            while (k + 1 <= i && d[i] - d[k] > Q) k++;
            ds[i] = min(ds[i], g[k] - (bri[k] ? Q - (d[i] - d[k]) : 0));
        }
        ds[1] = dt[tot] = 0, k = tot;
        for (int i = tot - 1; i; i--) {
            dt[i] = min(g[tot] - g[i], dt[i + 1] + g[i + 1] - g[i]);
            while (k - 1 >= i && d[k] - d[i] > Q) k--;
            dt[i] = min(dt[i], g[tot] - g[k] - (bri[k + 1] ? Q - (d[k] - d[i]): 0));
        }
        int ans = 2e9;
        for (int i = 1; i <= tot; i++) ans = min(ans, ds[i] + dt[i]);
        k = 1;
        for (int i = 2; i <= tot; i++) {
            while (k + 1 <= i && d[i] - d[k] > 2 * Q) k++;
            ans = min(ans, g[tot] - g[i] + g[k] - (bri[k] ? 2 * Q - (d[i] - d[k]) : 0));
        }
        printf("%d\n", ans);
    }
    return 0;
}










