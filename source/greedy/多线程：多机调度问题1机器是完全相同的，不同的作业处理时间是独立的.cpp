#include<bits/stdc++.h>
using namespace std;
int main(){
    int mMachine, nTask;

    cin >> mMachine;
    cin >> nTask;
    int *proc = new int[mMachine];// proc cur time cost vector
    int *cost = new int[nTask];//
    for (int i = 0; i < nTask;i++)
    {
        cin >> cost[i];
    }
    // sort
    int temp;
    for (int i = 0; i <= nTask - 2; i++)
    {
        for (int j = 0; j <= nTask - 2 - i;j++)
        {
            if(cost[j] < cost[j+1]){
                temp = cost[j];
                cost[j] = cost[j + 1];
                cost[j+1] = temp;
            }
        }
    }
    //
    vector<int> vec(cost, cost + nTask);
    if(nTask <= mMachine){
        cout << *max_element(vec.begin(),vec.end());
        return 0;
    }
    int time = cost[0];
    for (int i = 0; i < mMachine;i++){
        proc[i] = cost[i];
    }
    for (int i = 0; i < nTask;i++){
        cout << cost[i] << ",";
    }
    cout<< "排序后就是上一行，下面是最短时间" << endl;
    for (int i = mMachine; i < nTask; i++)
    {
        int curminpos = 0, curminTime = cost[0];
        for (int j = 1; j < mMachine; j++)
        {
            if (proc[j] < curminTime)
            {
                curminpos = j;
                curminTime = proc[j];
            }
        }
        proc[curminpos] += cost[i];

        if (time < proc[curminpos])
        {
            time = proc[curminpos];
            // cout << time << endl;
        }
        };
    cout << ""<< time << endl;
    return 0;
}
