/*
现在来谈谈必经点的总结了 https://blog.csdn.net/BerryKanry/article/details/78431091
原来考过一道求必经点的题，是求的两点之间的所有必进点，图是一张DAG
除了灭绝树以外，当时采用的方法是建一张反图，看哪些点是1能到且能到n的，把这张图扣出来，建成无向图求割点

后来又来一道题，有向图变成了无向图，还是两点之间的必经点
由于是有向图无法建反图，无法扣图，但是可以直接跑tarjan了
当时使用的方法是直接求割点，顺便记一个DFS序（伪），找到割点之后判断n在不在割点的v的子树里
这里的v指的是判断这个点是割点的哪一个点v

然后就是昨天这道题了
DAG上单源多路劲必经点
除了灭绝树以外暂且没有其他方法，支配树除外

https://www.luogu.com.cn/problem/P2597 problem

5
0
1 0
1 0
2 3 0
2 0


 * */

#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int v,last;
}ed[200010];

vector <int> frm[100010];

int n,S=0,num=0;
int head[100010],anc[100010][22],dep[100010],siz[100010],in[100010];

void add(int u,int v)
{
    num++,in[v]++;
    ed[num].v=v;
    ed[num].last=head[u];
    head[u]=num;
}

int lca(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=20;i>=0;i--)
        if(dep[anc[u][i]]>=dep[v])
            u=anc[u][i];
    if(u==v) return v;
    for(int i=20;i>=0;i--)
        if(anc[u][i]!=anc[v][i])
            u=anc[u][i],v=anc[v][i];
    return anc[u][0];
}

void init(int u)
{
    int f=0;
    for(int i=0;i<frm[u].size();i++)
        if(!f) f=frm[u][i]; else f=lca(frm[u][i],f);
    anc[u][0]=f,dep[u]=dep[f]+1;
    for(int i=1;i<=20;i++)
        anc[u][i]=anc[anc[u][i-1]][i-1];
}

void TOP()
{
    queue <int> state;
    state.push(S);
    while(!state.empty())
    {
        int u=state.front();
        state.pop();
        for(int i=head[u];i;i=ed[i].last)
        {
            int v=ed[i].v;
            in[v]--,frm[v].push_back(u);
            if(!in[v]) state.push(v),init(v);
        }
    }
}

void ReBuild()
{
    num=0;
    memset(head,0,sizeof(head));
    for(int i=1;i<=n;i++)
        add(anc[i][0],i);
}

void dfs(int u)
{
    siz[u]=1;
    for(int i=head[u];i;i=ed[i].last)
    {
        int v=ed[i].v;
        dfs(v);
        siz[u]+=siz[v];
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int u;
        while(scanf("%d",&u) && u)
            add(u,i);
    }
    for(int i=1;i<=n;i++)
        if(!in[i]) add(S,i);
    TOP();
    ReBuild();
    dfs(S);
    for(int i=1;i<=n;i++)
        printf("%d\n",siz[i]-1);
    return 0;
}















