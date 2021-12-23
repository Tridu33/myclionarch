#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct Job{
	int ID;
	int time;
}Job;
typedef struct JobNode{
	int ID;
	int time;
	JobNode *next;
}JobNode, *pJobNode;
typedef struct Header{
	int s;
	pJobNode next;
}Header, pHeader;
int SelectMin(Header *M, int m){
	int k = 0;
	for(int i=1; i<m; i++)
		if(M[i].s < M[k].s)
			k = i;
	return k;
}
int SelectMax(Header *M, int m){
	int k = 0;
	for(int i=1; i<m; i++)
		if(M[i].s > M[k].s)
			k = i;
	return k;
}
void Sort(Job *a, int n){
	Job temp;
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(a[i].time < a[j].time){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
}
void Print(Header *M, int m){
	JobNode *p;
	for(int i=0; i<m; i++){
		cout<<"第"<<i+1<<"台机器运行的作业ID为："; 
		p = M[i].next;
		while(p){
			cout<<p->ID<<" ";
			p = p->next;
		}
		cout<<endl;
	}
}
int Dispatch(Job *a, Header *M, int n, int m){
	int min, max;
	JobNode *p, *q;
	for(int i=0; i<n; i++){
		M[i].s = 0; M[i].next = NULL; 
	} 
	Sort(a, n);
	if(n <= m)
		return a[0].time;
	for(int j=0; j<n; j++){
		q = (pJobNode)malloc(sizeof(JobNode));
		min = SelectMin(M, m);
		M[min].s += a[j].time;
		q->ID = a[j].ID;
		q->time = a[j].time;
		q->next = NULL;
		if(!M[min].next)
			M[min].next = q;
		else{
			p = M[min].next;
			while(p->next)
				p = p->next;
			p->next = q;
		}
	}
	Print(M, m);
	max = SelectMax(M, m);
	return M[max].s;
}
int main(){
	int n, m, maxtime;
	Job a[10];
	Header M[10];
	cout<<"输入作业数和机器数："; 
	cin>>n>>m;
	cout<<"输入作业ID和时间："<<endl; 
	for(int i=0; i<n; i++){
		cin>>a[i].ID>>a[i].time;
	}
	maxtime = Dispatch(a, M, n, m);
	cout<<"作业全部运行完成所需最短时间为："<<maxtime<<endl;
}
/*
7 3
1 2
2 14
3 4
4 16
5 6
6 5
7 3
*/
