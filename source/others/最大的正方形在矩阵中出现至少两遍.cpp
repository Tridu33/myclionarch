#include<bits/stdc++.h>
using namespace std;
using lom = unsigned long long;
//链接：https://ac.nowcoder.com/acm/problem/51003
// 给定一个M行N列的01矩阵（只包含数字0或1的矩阵），再执行Q次询问，每次询问给出一个A行B列的01矩阵，求该矩阵是否在原矩阵中出现过。
 
const lom base1 = 131, base2 = 233;
const int M = 505;
int n, m;
char a[M][M];
lom _hash[M][M];
lom p1[M], p2[M];
 
void init()//初始化 
{
	p1[0] = p2[0] = 1;
	for(int i = 1; i <= 505; i++)
	{
		p1[i] = p1[i-1] * base1;
		p2[i] = p2[i-1] * base2;
	}
}
 
void Hash() //建立hash映射 
{
	_hash[0][0] = _hash[0][1] = _hash[1][0] = 0;
	
	for(int i = 1; i <= n; i++)//前缀和 
	for(int j = 1; j <= m; j++)
	_hash[i][j] = _hash[i][j-1] * base1 + a[i][j] - 'a';
	
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= m; j++)//二维前缀和 
	_hash[i][j] += _hash[i-1][j] * base2;
}
 
bool check(int x) //是否存在两个边长为x的矩阵 相同 
{
	map<lom,int> M;
	lom k;
	for(int i = x; i <= n; i++)
	for(int j = x; j <= m; j++)
	{
		k = _hash[i][j] - _hash[i-x][j] * p2[x] - _hash[i][j-x] * p1[x];
		//减去上边的长方形，减去左面的长方形 
		k += _hash[i-x][j-x] * p1[x] * p2[x];
		//加上多减去的左上角的矩阵 
		
		M[k]++;
		if(M[k] >= 2) return true;
	}
	
	return false;
}
 
int main()
{
	init();
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
	    cin >> a[i][j];
        }
    }
	
	Hash();
	
	int l = 1, r = max(n, m), ans = 0;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if(check(mid))
		{
			l = mid + 1;
			ans = mid;
		}
		else 
			r = mid - 1;
	}
	
	cout << ans << endl;
	
	return 0;
}
 
// God bless me