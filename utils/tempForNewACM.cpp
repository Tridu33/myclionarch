#include <iostream>
#include <ostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("in.txt"); // 已有输入文件
    ofstream fout("out.txt"); //输出文件
    streambuf *cinbackup;
    streambuf *coutbackup;
    coutbackup= cout.rdbuf(fout.rdbuf()); //用 rdbuf() 重新定向
    cinbackup= cin.rdbuf(fin.rdbuf()); //用 rdbuf() 重新定向
    cout<<"Hello world"<<endl; //去文件也
    char line[100];
    cin>>line; //从in.txt文件读入
    cout<<line<<endl; //写入 out.txt

    // 一维数组 vector<int>



    // 二维矩阵

    // Newcoder那些多行输入直接读取就因题而异


    // restore standard streambuf
    cin.rdbuf(cinbackup); // 取消，恢复键盘输入
    cout.rdbuf(coutbackup); //取消，恢复屏幕输出
    return 0;
}