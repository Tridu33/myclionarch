/*

【问题描述】
输入描述:
输入数据有多组, 每行表示一组输入数据。
每行的第一个整数为整数的个数n(1 <= n <= 100)。
接下来n个正整数, 即需要求和的每个正整数。
输出描述:
每组数据输出求和的结果
示例1
输入
4 1 2 3 4
5 1 2 3 4 5
输出
10
15

*/
#include <stdio.h>
#include <iostream>
#include <algorithm>//sort()
#include <vector>//vecotr
#include <sstream>//stringstream
using namespace std;
void num_case4()
{
	int num;
	while (~scanf("%d", &num))	// while(cin>>num)也行
	{
		int sum = 0;
		for (int i = 0; i < num; i++)
		{
			int a;
			scanf("%d", &a);
			sum += a;
		}
		printf("%d\n", sum);
	}
}

//C++语法
int main(){
    int a,b;
    freopen("debug\\in.txt","r",stdin); //输入重定向，输入数据将从in.txt文件中读取
    freopen("debug\\out.txt","w",stdout); //输出重定向，输出数据将保存在out.txt文件中
    num_case4(); // 
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
    return 0;
}