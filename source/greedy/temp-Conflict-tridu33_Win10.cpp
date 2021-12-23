//https://www.cnblogs.com/cxmhy/p/4477670.html
#include<bits/stdc++.h>
using namespace std;

int main(){
    int mMachine, nTask,restime;

    cin >> mMachine;
    cin >> nTask;
    int *cost = new int[mMachine];//机器处理时间
    int *curendtime = new int[mMachine];//记录当下机器用时，比较 最短执行时间= 已用+当下任务
    for (int i = 0; i < mMachine;i++)
    {
        cin >> cost[i];
        curendtime[i] = 0;
    }
    //
    int min , min_index;
    vector<int> vec(cost, cost + mMachine);
    for (int i = 0; i < nTask; i++)
    {
        min = curendtime[0] + cost[0];
        min_index = 0;
        for (int j = 0; j < mMachine; j++)
        {
            if(curendtime[j] + cost[j] < min){
                min_index = j;
                min = curendtime[i] + cost[j];
            }
        }
        curendtime[min_index] += cost[min_index];
        restime = curendtime[min_index];
    };
    cout << ""<< restime << endl;
    for (int i = 0; i < mMachine;i++)
    {
        cout << i+1 << "机器任务个数=" << curendtime[i]/cost[i] << endl;
    }
    return 0;
}
