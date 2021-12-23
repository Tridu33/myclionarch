#include<bits/stdc++.h>
// https://www.mina.moe/archives/9619
using namespace std;
#define RI register int
int read() {
    int q=0;char ch=' ';
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') q=q*10+ch-'0',ch=getchar();
    return q;
}
typedef long long LL;
const int N=50005,M=100005;
int n,m,tim;
int dfn[N],repos[N],mi[N],fa[N],f[N],semi[N],idom[N],ans[N];
struct graph{
    int tot,h[N],ne[M],to[M];
    void clear() {tot=0;for(RI i=0;i<=n;++i) h[i]=0;}//此题数据有误所以应从 i=0 开始清空
    void add(int x,int y) {to[++tot]=y,ne[tot]=h[x],h[x]=tot;}
}g,rg,ng,tr;

void init() {
    tim=0;g.clear(),rg.clear(),ng.clear(),tr.clear();
    for(RI i=1;i<=n;++i)
        repos[i]=dfn[i]=idom[i]=fa[i]=ans[i]=0,mi[i]=semi[i]=f[i]=i;
}
void tarjan(int x) {
    dfn[x]=++tim,repos[tim]=x;
    for(RI i=g.h[x];i;i=g.ne[i])
        if(!dfn[g.to[i]]) fa[g.to[i]]=x,tarjan(g.to[i]);
}
int find(int x) {
    if(x==f[x]) return x;
    int tmp=f[x];f[x]=find(f[x]);
    if(dfn[semi[mi[tmp]]]<dfn[semi[mi[x]]]) mi[x]=mi[tmp];
    return f[x];
}
void dfs(int x,LL num) {
    ans[x]=num+x;
    for(RI i=tr.h[x];i;i=tr.ne[i]) dfs(tr.to[i],num+x);
}
void work() {
    for(RI i=n;i>=2;--i) {
        int x=repos[i],tmp=n;
        for(RI j=rg.h[x];j;j=rg.ne[j]) {
            if(!dfn[rg.to[j]]) continue;//此题数据有误
            if(dfn[rg.to[j]]<dfn[x]) tmp=min(tmp,dfn[rg.to[j]]);
            else find(rg.to[j]),tmp=min(tmp,dfn[semi[mi[rg.to[j]]]]);
        }
        semi[x]=repos[tmp],f[x]=fa[x],ng.add(semi[x],x);

        x=repos[i-1];
        for(RI j=ng.h[x];j;j=ng.ne[j]) {
            int y=ng.to[j];find(y);
            if(semi[mi[y]]==semi[y]) idom[y]=semi[y];
            else idom[y]=mi[y];//此时 idom[mi[y]] 可能并未找到
        }
    }
    for(RI i=2;i<=n;++i) {
        int x=repos[i];
        if(idom[x]!=semi[x]) idom[x]=idom[idom[x]];
        tr.add(idom[x],x);
    }
    dfs(n,0);
}
int main()
{
    int x,y;
    while(~scanf("%d%d",&n,&m)) {
        init();
        for(RI i=1;i<=m;++i)
            x=read(),y=read(),g.add(x,y),rg.add(y,x);
        tarjan(n);work();
        for(RI i=1;i<n;++i) printf("%d ",ans[i]);
        printf("%d\n",ans[n]);
    }
    return 0;
}
