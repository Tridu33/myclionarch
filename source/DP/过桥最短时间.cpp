










动态规划-算法题 - Zopen的文章 - 知乎
https://zhuanlan.zhihu.com/p/68228645


#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int a[10010];
int dp[10010];//dp[n]表示n个孩子过河需要的时间

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dp[1]=a[1];
    dp[2]=a[2];
    for(int i=3;i<=n;i++){
        dp[i]=min(dp[i-1]+a[0]+a[i],dp[i-2]+a[0]+2*a[1]+a[i]);
    }
    cout<<dp[n]<<endl;
    return 0;
}










/* ccnu 2018新生赛A题 Author: Y_Cl */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
using namespace std;

int vis[4];
int cost[4]={1,2,5,10};
int Ans;

void go(int time);
void back(int time);

void go(int time)
{
    for (int i=0; i<4; ++i)
        if (vis[i] == 0)
        {
            bool flag=0;
            for (int j=0; j<4; ++j)
                if (i!=j && vis[j] == 0)
                {
                    flag=1;
                    vis[i] = vis[j] = 1;
                    back(time+max(cost[i],cost[j]));
                    vis[i] = vis[j] = 0;
                }
            if (flag == 0) // 鍙墿涓嬩竴鍙┈娌¤繃娌?
            {
                vis[i] = 1;
                back(time+cost[i]);
                vis[i] = 0;
            }
        }
}

void back(int time)
{
    bool flag=0;
    for (int i=0; i<4; ++i)
        if (vis[i] == 0) flag=1;
    if (!flag) 
    {
        Ans=min(Ans,time);
        return ;
    }
    for (int i=0; i<4; ++i)
        if (vis[i] == 1)
        {
            vis[i] = 0;
            go(time+cost[i]);
            vis[i] = 1;
        }
}

int main()
{
    Ans=1000000;
    vis[0] = vis[1] = vis[2] = vis[3] = 0;
    go(0);
    printf("%d\n",Ans);
    return 0;
}


















#include "stdafx.h"

#define N   5

#define SIZE 64

 

//将人员编号：小明-0，弟弟-1，爸爸-2，妈妈-3，爷爷-4

//每个人的当前位置：0--在桥左边， 1--在桥右边

int Position[N];   

//过桥临时方案的数组下标；临时方案；最小时间方案；

int Index, TmpScheme[SIZE], Scheme[SIZE];  

//最小过桥时间总和，初始值100；每个人过桥所需要的时间

int MinTime=100, Time[N]={1, 3, 6, 8,12}; 

//寻找最佳过桥方案。Remnant:未过桥人数; CurTime:当前已用时间;

//Direction:过桥方向,1--向右,0--向左

void Find(intRemnant,int CurTime, intDirection)

{

    if(Remnant==0){                               //所有人已经过桥，更新最少时间及方案

        MinTime=CurTime;

        for(int i=0; i<SIZE && TmpScheme[i]>=0;i++)

        {

            Scheme[i]=TmpScheme[i];

        }

    }else if(Direction==1){                        // 过桥方向向右，从桥左侧选出两人过桥

        for(int i=0; i<N; i++)                   

        {

            if(Position[i]==0&& CurTime+Time[i]<MinTime){

                TmpScheme[Index++] = i;

                Position[i] = 1;

                for(int j=0; j<N; j++)           

                {

                    int TmpMax =(Time[i]>Time[j] ? Time[i] : Time[j]);

                    if(Position[j]==0&& CurTime+TmpMax<MinTime)

                    {

                        TmpScheme[Index++] =j;   

                        Position[j] = 1;       

                        Find(Remnant-2, CurTime+TmpMax,!Direction);

                        Position[j] = 0;       

                        TmpScheme[--Index] =-1;

                    }

                }

                Position[i] = 0;

                TmpScheme[--Index] = -1;

            }

        }

    }else{       // 过桥方向向左，从桥右侧选出一个人回来送灯

        for(int j=0; j<N; j++)

        {

            if(Position[j]==1&& CurTime+Time[j] < MinTime)

            {

                TmpScheme[Index++] = j;

                Position[j] = 0;

                Find(Remnant+1,CurTime+Time[j], !Direction);

                Position[j] = 1;

                TmpScheme[--Index] = -1;

            }

        }

    }

}

int main(intargc,char* argv[])

{

    for(int i=0; i<SIZE; i++)            // 初始方案内容为负值，避免和人员标号冲突

        Scheme[i] = TmpScheme[i] = -1;

 

Find(N, 0,1);                          // 查找最佳方案

 

    printf("MinTime=%d:", MinTime);      // 输出最佳方案

    for(int i=0; i<SIZE && Scheme[i]>=0; i+=3)

        printf("  %d-%d %d", Scheme[i], Scheme[i+1], Scheme[i+2]);

    printf("\b\b  ");

    returngetchar();

}




#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
 
#define LL64 __int64
#define LL long long
#define N 1010
#define M 210
 
int a[N];
 
int main()
{
	int n;
	
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		if (n == 1)
		{
			printf("%d\n", a[0]);
			continue;
		}
		if (n == 2)
		{
			printf("%d\n", max(a[0], a[1]));
			continue;
		}
		if (n == 3)
		{
			printf("%d\n", a[0] + a[1] + a[2]);
			continue;
		}
		sort(a, a + n);
		int s = 0;
		for (int i = n - 1; i > 0; i -= 2)
		{
			if (i == 2) s += a[i] + a[i - 1] + a[i - 2];
			else if (i == 1) s += max(a[i], a[i - 1]);
			else if (a[i - 1] + a[0] > a[1] * 2) s += a[1] * 2 + a[i] + a[0];
			else s += a[0] + a[i - 1] + a[i] + a[0];
		}
		printf("%d\n", s);
	}
	
	return 0;
}



















