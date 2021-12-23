#include<iostream>
#include<algorithm>
#include<vector>
/*
有n个机器，m个任务，1<=n,m<=100000，每个机器都有工作时间的最大限制0< xi<1000和完成的最大难度0<=yi<=100，每个任务也有所需要的时间和难度，只要机器的时间大于等于任务，难度大于等于任务，该任务就可以被机器完成，每完成一个任务就可以得到200*xi+3*yi的money，问最多能有多少个任务被完成，并且保证完成任务数量最多的情况下，所得到的money最多是多少？

解法：贪心算法，根据公式200*xi+3*yi可知，尽可能的将机器去执行xi较大的任务，可以获得更多的money。
第一步：将机器和任务都按照工作时间xi排序，如果xi相同则按照yi排序。（逆序）
第二部：用任务的时间来找到所有符合条件的机械，再从中找到最接近任务等级的机械，即可。如果你找到比任务x，y大的机械就直接计算的话，就会出错。（如果这点想不通的话，你可以想一下，下面这组数据）：
2 2
150 5
102 2
100 3
101 1

//杠精一下， 1 2 999 100 2 1 1 100 答案: 1 500 该代码输出:1 403 所以这道题的贪心解法就是错的.NP完全暴力搜索
*/
using namespace std;
struct node {
    int x, y;
};
bool compare(node a, node b) {
    if (a.x == b.x)
        return a.y > b.y;
    else
        return a.x > b.x;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<node> machine(n);
    vector<node> task(m);
    for (int i = 0; i < n; i++)
        cin >> machine[i].x >> machine[i].y;
    for (int j = 0; j < m; j++)
        cin >> task[j].x >> task[j].y;
    sort(machine.begin(), machine.end(), compare);
    sort(task.begin(), task.end(), compare);
    int ans = 0, sum = 0;
    int temp[100];
    for (int i = 0, j = 0; i < task.size(); i++) {
        while (j <machine.size() && machine[j].x >= task[i].x) {
            temp[machine[j].y]++;
            j++;
        }//第一个 while 找到 时间上能够处理当前任务的机器（先忽略等级要求），然后将 cnt 中对应等级位置加一操作。
        //计数这个难度等级的任务下有多少个机器能做的count。
        for (int k = task[i].y; k <= 100; k++) {
            if (temp[k]) {
                ans += 200 * task[i].x + 3 * task[i].y;
                sum++;//做完一个
                temp[k]--;//做完减回去这个难度等级下还有几个机器能做
                break;
            }
        }//第二个 for 循环，看对应等级上，有没有机器可以处理相应的任务，while循环已经保证了时间上的可操作性
    }
    cout << sum<< " "<<ans;
    system("pause");
    return 0;
}

/*
//安排机器
#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn  = 1e5 + 10;
struct node{
	int time,grade;
}machine[maxn],task[maxn]; 
 
int cnt[105];
 
int cmp(node a,node b){
	if(a.time==b.time){
		return a.grade>b.grade;
	}
	return a.time>b.time;
}
 
int main(){
	int numMachine,numTask;
	scanf("%d%d",&numMachine,&numTask);
	for(int i=0;i<numMachine;i++){
		scanf("%d%d",&machine[i].time,&machine[i].grade);
	}
	for(int i=0;i<numTask;i++){
		scanf("%d%d",&task[i].time,&task[i].grade);
	}
	sort(machine,machine+numMachine,cmp);
	sort(task,task+numTask,cmp);
//	for(int i=0;i<numMachine;i++){
//		printf("%d %d\n",e[i].time,e[i].grade);
//	}
//	for(int i=0;i<numTask;i++){
//		printf("%d %d\n",f[i].time,f[i].grade);
//	}
	
	int num = 0;
	LL ans = 0;
	memset(cnt,0,sizeof(cnt));
	int i,j,k;
	for(i=0,j=0;i<numTask;i++){ //对于每个任务而言 
		while(j<numMachine && machine[j].time>=task[i].time){
			cnt[machine[j].grade]++;
			j++;
		}
		for(k=task[i].grade;k<=100;k++){
			if(cnt[k]){
				num++;
				cnt[k]--;
				ans = ans+200*task[i].time + 3*task[i].grade;
				break;
			}
		}
	}
	printf("%d %lld\n",num,ans);
	return 0;
}
*/