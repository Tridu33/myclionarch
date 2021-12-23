#include<iostream>
#include <queue>
#include <map>
using namespace std;
int getbc(vector<int> &bc, int v){
    if(bc[v]==v) return v;
    else return bc[v] = getbc(bc, bc[v]);
}//https://blog.csdn.net/brandohero/article/details/40216903
/*
任务调度问题（Google面试题）
N个job，所有job都一样，M台机器，每个机器i处理job的时间是ci，求最短时间把job都弄完
        相当于M条队列，放不同宽度的砖头，最后砖头数量一定，问M条队列的宽度最小值。
贪心： 每次选择ti+ci最小的队列放砖头。ti为队列i当前宽度。ti+ci为放入砖头后的队列i宽度。
另外放砖头后需要更新队列i的（ti+ci)，更新方法： 线段树（叶节点i保存队列i当前的ti+ci）中更新区间[i， i]（从ti+ci变成(ti+ci)+ci ） 
下一次找出根节点，即ti‘+ci’最小的叶节点编号i‘，对应宽度最小的砖头队列继续放砖头。
统计M条队列的宽度： max（ 叶节点的值-ci）。
 另外一种办法：使用优先队列（小顶堆）Priority<pair<int, int> > , 来存储最小（宽度）队列的编号。 每次弹出一个元素p，检查p.first==t[p.second]+c[p.second].  是则有效。p.second为最小队列编号。
*/
int main(){
    int n, m; cin>>n>>m;
    typedef pair<int, pair<int,int> > EDG;
    priority_queue< EDG, vector<EDG>, greater<EDG> > que;
    vector<int> bc(n);
    for(int i = 0; i<n; i++) bc[i] = i;
    for(int i = 0 ;i<m; i++){
        int a, b, d; cin>>a>>b>>d; a--, b--;
        que.push(EDG(d, pair<int, int>(a, b)));
    }
    int sum = 0;
    for(int i = 1; i<n; i++){
        while(!que.empty()){
            EDG e = que.top(); que.pop();
            int a = e.second.first, b = e.second.second, d = e.first;
            if(getbc(bc, a)!=getbc(bc, b)){
                sum+=d;
                bc[getbc(bc, a)]=getbc(bc, b);
                break;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}