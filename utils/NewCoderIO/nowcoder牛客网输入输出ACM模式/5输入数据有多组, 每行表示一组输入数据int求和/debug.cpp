/*

输入描述:
输入数据有多组, 每行表示一组输入数据。

每行不定有n个整数，空格隔开。(1 <= n <= 100)。
1
输出描述:
每组数据输出求和的结果
示例1
输入
1 2 3
4 5
0 0 0 0 0
输出
6
9
0
nowcoder

*/
#include <stdio.h>
#include <iostream>
#include <algorithm>//sort()
#include <vector>//vecotr
#include <sstream>//stringstream
using namespace std;

void num_case3()
{
	string str;
	while (getline(cin, str))// 一行一行的读取 
	{ 
		stringstream ss(str);
		int sum = 0;
		int v;
		// 每行不知道有几个整数，通过stringstream来循环读取
		while (ss >> v) {
			sum += v;
		}
		cout << sum << endl;
	}
	/*
	//或者可用stoi
	string str;
	while(getline(cin,str))
	{
		stringstream ss;
		ss<<str;
		string temp;
		int sum=0;
		while(getline(ss,temp,' '))
		{
			sum+=stoi(temp);
		}
		cout<<sum<<endl;
	}
	*/
}



//C++语法
int main(){
    int a,b;
    freopen("debug\\in.txt","r",stdin); //输入重定向，输入数据将从in.txt文件中读取
    freopen("debug\\out.txt","w",stdout); //输出重定向，输出数据将保存在out.txt文件中
    num_case3(); // 
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
    return 0;
}