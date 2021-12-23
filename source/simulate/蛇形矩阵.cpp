// Source: 腾讯公司模拟编程题
// Author: Yang Qiang
// Date  : 2016/9/2

// 题目: 按行输出蛇形矩阵
// 示例: [1 2 3
//        4 5 6
//        7 8 9]
#include <iostream>
using namespace std;
int main()
{
    void print_snake(int n);
    int n;
    cin>>n;
    print_snake(n);
    return 0;
}
 
void print_snake(int n)
{
    int i,j,k,circle=-1;
    int matrix[n][n];
    int timer=1,temp;
    for(temp=n;temp>1;temp=temp-2)
    {
        circle++;
        j=i=circle;
        for(k=j+temp-1;j<k;++j)
        {
            matrix[i][j]=timer++;
        }
 
 
        for(k=i+temp-1;i<k;++i)
        {
            matrix[i][j]=timer++;
        }
        for(;j>circle;--j)
        {
            matrix[i][j]=timer++;
        }
        for(;i>circle;--i)
        {
              matrix[i][j]=timer++;
        }
 
 
    }
    if(temp==1)
       matrix[++i][++j]=timer++;
 
 
     for(i=0;i<n;++i)
       {
         for(j=0;j<n;++j)
           cout<<matrix[i][j]<<"    ";
          cout<<endl;
       }
 
}

/*

#include<iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        //检测不合理输入
        if(n<=0) return 0;

        int **max=new int*[n]; //建立二维数组
        bool **maxflag=new bool*[n]; //建立标志矩阵
        for(int i=0; i<n; i++)
        {
            max[i]=new int[n];
            maxflag[i]=new bool[n];
        }

        //标志矩阵初始化
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                maxflag[i][j]=0;

        //蛇形存入数字
        int num=1,row=0,col=0;
        while(num<=n*n)
        {
            while(row>=0 && col>=0 && col<n && row<n && maxflag[row][col]==0 )
            {
                max[row][col]=num++; //向右
                cout<<max[row][col];
                maxflag[row][col]=1; //更改标志位
                col++;
            }
            col--;row++;
            while(row>=0 && col>=0 && col<n && row<n && maxflag[row][col]==0 )
            {
                max[row][col]=num++; //向下
                cout<<max[row][col];
                maxflag[row][col]=1; //更改标志位
                row++;
            }
            row--;col--;

            while(row>=0 && col>=0 && col<n && row<n && maxflag[row][col]==0 )
            {
                max[row][col]=num++; //向左
                cout<<max[row][col];
                maxflag[row][col]=1; //更改标志位
                col--;
            }
            col++;row--;
            while(row>=0 && col>=0 && col<n && row<n && maxflag[row][col]==0 )
            {
                max[row][col]=num++; //向上
                cout<<max[row][col];
                maxflag[row][col]=1; //更改标志位
                row--;
            }
            row++;col++;
        }
        cout<<endl;
        //按行输出蛇形矩阵
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cout<<max[i][j];
        cout<<endl;
    }
}

*/