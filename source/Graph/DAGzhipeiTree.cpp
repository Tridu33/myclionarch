
// https://www.luogu.com.cn/problem/P2597



//  https://blog.csdn.net/Scar_Halo/article/details/102809512

/*
5
0
1 0
1 0
2 3 0
2 0
 * */



#include<bits/stdc++.h>
#define rint register int
#define deb(x) cerr<<#x<<" = "<<(x)<<'\n';
using namespace std;
typedef long long ll;
typedef pair <int,int> pii;
const ll mod = 1e9 + 7;
const int maxn = 5e4 + 10;
int n, m, cnt, ans[maxn];
int in[maxn], tp[maxn];
int f[maxn][25], dep[maxn];
vector <int> g[maxn];
vector <int> t[maxn], fa[maxn];

int lca(int x, int y){
    if(dep[x] < dep[y]) swap(x, y);
    for(int i=20; ~i; i--)
        if(dep[f[x][i]] >= dep[y])
            x = f[x][i];
    if(x == y) return x;
    for(int i=20; ~i; i--)
        if(f[x][i] ^ f[y][i])
            x=f[x][i], y=f[y][i];
    return f[x][0];
}

void build(int x){
    int lcaf = fa[x][0];
    for(int i=1; i<fa[x].size(); i++)
        lcaf = lca(lcaf, fa[x][i]);
    t[lcaf].push_back(x);
    dep[x] = dep[lcaf] + 1;
    f[x][0] = lcaf;
    for(int i=1; i<=20; i++)
        f[x][i] = f[f[x][i-1]][i-1];
}

void tp_sort(){
    queue <int> Q;
    for(int i=1; i<=n; i++)
        if(!in[i]) {
            in[i]++;
            g[0].push_back(i);
            fa[i].push_back(0);
        }
    Q.push(0);
    while(!Q.empty()){
        int q = Q.front();
        Q.pop();
        tp[cnt++] = q;
        for(auto i : g[q]){
            in[i]--;
            if(!in[i]) {
                Q.push(i);
                build(i);
            }
        }
    }
}

void dfs(int x){
    ans[x] = 1;
    for(auto i : t[x]){
        dfs(i);
        ans[x] += ans[i];
    }
}

int main() {
    scanf("%d", &n);
    for(int i=1, x; i<=n; i++){
        while(1){
            scanf("%d", &x);
            if(x==0) break;
            g[x].push_back(i);
            fa[i].push_back(x);
            in[i]++;
        }
    }

    tp_sort();
    dfs(0);
    for(int i=1; i<=n; i++)
        printf("%d\n", ans[i]-1);
}
