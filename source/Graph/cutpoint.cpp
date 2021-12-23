#include<iostream>
#include<list>
#include<algorithm>  //for min
#define NIL -1
// https://blog.csdn.net/qq_40691051/article/details/103092444
using namespace std;
class Graph
{
	int n;		//图中节点个数
	list<int>* adj;   //邻接表
	void APUtil(int v, bool visited[], int depth[], int low[],
			int parent[], int curDepth, bool AP[]);
	bool isBCUtil(int v, bool visited[], int depth[], int low[],
			int parent[], int curDepth);
public:
	Graph(int _n);
	void addEdge(int v,int w);
	void AP();			//求出连通图中的关节点
	bool isBC();
};

Graph::Graph(int _n)
{
	n = _n;
	adj = new list<int>[_n];
}
void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}
void Graph::APUtil(int u,bool visited[],int depth[],int low[],
			int parent[],int curDepth,bool AP[])
{
	visited[u] = true;				//已访问
	int children = 0;				//孩子数

	// 初始化u的深度和能到达的深度最小的祖先
	depth[u] = low[u] = curDepth;

	list<int>::iterator it;
	for( it = adj[u].begin(); it != adj[u].end(); it++)
	{
		int v = *it;

		if( !visited[v])		//v没被访问过
		{
			parent[v] = u;		//设置v的双亲
			children++;			//u的子女+1
			APUtil(v, visited, depth, low, parent, curDepth + 1, AP);

			//访问完v后回溯到这里,检查下u的子孙里有没有那个能
			//有绕过u能到达的深度最小的祖先,有的话u从子孙那边
			//到那个祖先 ，更新low[u]
			low[u] = min(low[u], low[v]);

			//判断:
			//1、如果u是根结点(整颗生成树的根,其双亲为-1，即NIL)
			//如果children >  1,则u是关节点
			if( parent[u] == NIL && children > 1)
			{
				AP[u] = true;
			}

			//2、不是根结点，但是有子女v无法绕过它u到它u的祖先w
			//u是关节点,此时low[v] >= depth[u]
			if( parent[u] != NIL && low[v] >= depth[u])
			{
				AP[u] = true;
			}
		}
		else if( v != parent[u])
		{//v访问过了，说明v是当前节点u的祖先,v找到了一条边(回边到v的祖先),
		//这里排除下v是u的双亲(因为v是u的双亲的话处理的就不是回边了，这条边在DFS树)
			low[u] = min(low[u], depth[v]);			//更新low[u];
		}
	}
}
void Graph::AP()
{
	bool *visited = new bool[n];
	int *parent = new int[n];
	int *low = new int[n];
	int *depth = new int[n];
	bool *AP = new bool[n];

	for(int i = 0; i < n; i++)
	{
		AP[i] = false;
		parent[i] = NIL;
		visited[i] = false;
	}
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			APUtil(i,visited,depth,low,parent,0,AP);
		}
	}

	for(int i = 0; i < n; i++)
	{
		if(AP[i] == true)
		{
			cout<<i<<"  ";
		}
	}
	cout<<endl;
}
bool Graph::isBCUtil(int u,bool visited[],int depth[],int low[],
			int parent[],int curDepth)
{
	visited[u] = true;				//已访问
	int children = 0;				//孩子数

	// 初始化u的深度和能到达的深度最小的祖先
	depth[u] = low[u] = curDepth;

	list<int>::iterator it;
	for( it = adj[u].begin(); it != adj[u].end(); it++)
	{
		int v = *it;

		if( !visited[v])		//v没被访问过
		{
			parent[v] = u;		//设置v的双亲
			children++;			//u的子女+1

			if( isBCUtil(v, visited, depth, low, parent, curDepth + 1) == true)
			{
				return true;
			}
			//访问完v后回溯到这里,检查下u的子孙里有没有那个能
			//有绕过u能到达的深度最小的祖先,有的话u从子孙那边
			//到那个祖先 ，更新low[u]
			low[u] = min(low[u], low[v]);

			//判断:
			//1、如果u是根结点(整颗生成树的根,其双亲为-1，即NIL)
			//如果children >  1,则u是关节点
			if( parent[u] == NIL && children > 1)
			{
				return true;
			}

			//2、不是根结点，但是有子女v无法绕过它u到它u的祖先w
			//u是关节点,此时low[v] >= depth[u]
			if( parent[u] != NIL && low[v] >= depth[u])
			{
				return true;
			}
		}
		else if( v != parent[u])
		{//v访问过了，说明v是当前节点u的祖先,v找到了一条边(回边到v的祖先),
		//这里排除下v是u的双亲(因为v是u的双亲的话处理的就不是回边了，这条边在DFS树)
			low[u] = min(low[u], depth[v]);			//更新low[u];
		}
	}
	return false;
}
bool Graph::isBC()
{
	bool *visited = new bool[n];
	int *parent = new int[n];
	int *low = new int[n];
	int *depth = new int[n];

	for(int i = 0; i < n; i++)
	{
		parent[i] = NIL;
		visited[i] = false;
	}

	//isBCUtil返回图中有没有关节点
	if( isBCUtil(0,visited,depth,low,parent,0) == true)
	{
		return false;
	}

	for(int i = 0; i < n; i++ )
	{
		if(visited[i] == false)
		{//DFS后还有节点没被访问过，连通图都不是
			return false;
		}
	}
	return true;
}
int main()
{
	cout<<"输入图的关节点有:"<<endl;
//	Graph g1(15);
//	g1.addEdge(0,1);
//	g1.addEdge(1,2);
//	g1.addEdge(1,6);
//	g1.addEdge(2,3);
//	g1.addEdge(2,4);
//	g1.addEdge(3,4);
//	g1.addEdge(4,5);
//	g1.addEdge(5,6);
//	g1.addEdge(6,7);
//	g1.addEdge(1,8);
//	g1.addEdge(0,9);
//	g1.addEdge(9,10);
//	g1.addEdge(10,11);
//	g1.addEdge(10,13);
//	g1.addEdge(11,12);
//	g1.addEdge(12,13);
    Graph g0(4);
    g0.addEdge(0,1);
    g0.addEdge(0,2);
    g0.addEdge(2,3);
    Graph g1=g0;

    g1.AP();
	cout<<"g1是不是双连通图:"<<endl;
	cout<<(g1.isBC() ? "是":"不是")<<endl;

//	cout<<"g2是不是双连通图:"<<endl;
//	Graph g2(2);
//	g2.addEdge(0,1);
//	cout<<(g2.isBC() ? "是":"不是")<<endl;
//
//	cout<<"g3是不是双连通图:"<<endl;
//	Graph g3(4);
//	g3.addEdge(0,1);
//	g3.addEdge(1,2);
//	g3.addEdge(1,3);
//	cout<<(g3.isBC() ? "是":"不是")<<endl;
//
//	cout<<"g4是不是双连通图:"<<endl;
//	Graph g4(5);
//    g4.addEdge(1, 0);
//    g4.addEdge(0, 2);
//    g4.addEdge(2, 1);
//    g4.addEdge(0, 3);
//    g4.addEdge(3, 4);
//    cout<<(g4.isBC() ? "是":"不是")<<endl;
//
//  	cout<<"g5是不是双连通图:"<<endl;
//    Graph g5(3);
//    g5.addEdge(0, 1);
//    g5.addEdge(1, 2);
//    g5.addEdge(2, 0);
//    cout<<(g5.isBC() ? "是":"不是")<<endl;
	return 0;
}
