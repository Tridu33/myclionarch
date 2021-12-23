/*

输出描述:
对于每组测试用例，输出一行排序过的字符串，每个字符串通过空格隔开
示例1:
输入
a c bb
f dddd
nowcoder
输出：
a bb c
dddd f
nowcoder

*/
#include <stdio.h>
#include <iostream>
#include <algorithm>//sort()
#include <vector>//vecotr
#include <sstream>//stringstream
using namespace std;


void str_case2()
{
	string s;
	while (getline(cin, s))
	{
		vector<string> str;
		stringstream ss;
		ss << s;
		string temp;
		while (getline(ss, temp, ' '))
		{
			str.push_back(temp);
		}
		sort(str.begin(), str.end());
		for (int i = 0; i < str.size(); i++)
			cout << str[i] << " ";
		cout << endl;

	}
}


//C++语法
int main(){
    int a,b;
    freopen("debug\\in.txt","r",stdin); //输入重定向，输入数据将从in.txt文件中读取
    freopen("debug\\out.txt","w",stdout); //输出重定向，输出数据将保存在out.txt文件中
    str_case2(); // 
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
    return 0;
}