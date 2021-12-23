/*

输入描述 :
输入有两行，第一行n
第二行是n个空格隔开的字符串
输出描述 :
输出一行排序后的字符串，空格隔开，无结尾空格
例子：
5
c d a bb e

*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


void str_case1()
{
	vector<string> str;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		string temp;
		cin >> temp;
		str.push_back(temp);
	}
	sort(str.begin(), str.end());
	for (int i = 0; i < str.size(); i++)
		cout << str[i] << " ";
}

//C++语法
int main(){
    int a,b;
    freopen("debug\\in.txt","r",stdin); //输入重定向，输入数据将从in.txt文件中读取
    freopen("debug\\out.txt","w",stdout); //输出重定向，输出数据将保存在out.txt文件中
    str_case1(); // 
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
    return 0;
}