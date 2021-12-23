#include <bits/stdc++.h>
using namespace std;
/*
https://ac.nowcoder.com/acm/problem/51003
链接：https://ac.nowcoder.com/acm/problem/51003
来源：牛客网

给定一个M行N列的01矩阵（只包含数字0或1的矩阵），
再执行Q次询问，每次询问给出一个A行B列的01矩阵，
求该矩阵是否在原矩阵中出现过。
*/
const int mac=1e3+10;
const int base1=131,base2=137;
typedef unsigned long long ull;

char s[mac][mac];
ull hashs[mac][mac],mos[mac*mac],sub_hash[120][mac];
ull pw1[mac],pw2[mac];

void get_hash(int n,int m,int type)
{
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (type) hashs[i][j]=hashs[i][j-1]*base1+s[i][j];
			else sub_hash[i][j]=sub_hash[i][j-1]*base1+s[i][j];
		
	for (int j=1; j<=m; j++)
		for (int i=1; i<=n; i++)
			if (type) hashs[i][j]=hashs[i-1][j]*base2+hashs[i][j];
			else sub_hash[i][j]=sub_hash[i-1][j]*base2+sub_hash[i][j];
	
}

int main(int argc, char const *argv[])
{
	int n,m,a,b;
	scanf ("%d%d%d%d",&n,&m,&a,&b);
	for (int i=1; i<=n; i++)
		scanf ("%s",s[i]+1);
	get_hash(n,m,1);
	int cnt=0;
	pw1[0]=pw2[0]=1;
	for (int i=1; i<=max(n,m); i++) pw1[i]=pw1[i-1]*base1,pw2[i]=pw2[i-1]*base2;
	for (int i=a; i<=n; i++){
		for (int j=b; j<=m; j++){
			ull sb=hashs[i][j]-hashs[i-a][j]*pw2[a]-hashs[i][j-b]*pw1[b]+hashs[i-a][j-b]*pw2[a]*pw1[b];
			mos[++cnt]=sb;
		}
	}
	sort(mos+1,mos+cnt+1);
	int q;
	scanf ("%d",&q);
	while (q--){
		for (int i=1; i<=a; i++)
			scanf ("%s",s[i]+1);
		get_hash(a,b,0);
		int flag=0;
		int pos=lower_bound(mos+1,mos+1+cnt,sub_hash[a][b])-mos-1;
		if (pos<cnt && mos[pos+1]==sub_hash[a][b]) flag=1;
		if (flag) printf("1\n");
		else printf("0\n");
	}
	return 0;
}