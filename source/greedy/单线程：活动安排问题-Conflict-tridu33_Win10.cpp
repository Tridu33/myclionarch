#include<bits/stdc++.h>
using namespace std;

struct  activity
{
    int start;
    int end;
    int state;//choose or not
};

int main(){
    int act_cnt;
    cin >> act_cnt;// count of activities
//以空格和换行对于cin都是结束符
/*
3
1 2
3 4
4 5
排完序的活动为：
3,4   4,5   0,4113
*/
cin.get();//cin.get()会把回车('\n')当作字符读入.而cin>>则会跳过回车或空格
cin.clear(); //flush the flag
cin.sync(); //clear the buffer
    activity *acts = new activity[act_cnt];

    for (int i = 0; i < act_cnt;i++)
    {
        cin >> acts[i].start >> acts[i].end;
        cin.get();
        cin.clear(); //flush the flag
        cin.sync(); //clear the buffer
        // cout << i << "=i,intput is :" << acts[i].end << acts[i].start << endl;
    }
    // bubble sort
    int temp_start, temp_end;
    for (int i = 0; i <= act_cnt - 2; i++)
    {
        for (int j = 0; j <= act_cnt - 2 - i;j++)
        {
            if(acts[i].end > acts[i+1].end){
                temp_start = acts[i].start;
                acts[i].start = acts[i + 1].start;
                acts[i+1].start = temp_start;
           
                temp_end = acts[i].end;
                acts[i].end = acts[i + 1].end;
                acts[i + 1].end = temp_end;
            }
        }
    }
    cout<<"排完序的活动为："<<endl;
	for(int i=0;i<act_cnt;i++){
		cout<<acts[i].start<<","<<acts[i].end;
		cout<<"   ";
	}
    cout << endl;
    // assign
    int i = 0;
    acts[i].state = true;

    // for (int j = 0不可以; j < act_cnt;j++)
    for (int j = 1; j < act_cnt;j++)
    {
        if(acts[i].start <= acts[j].end){// end of i <= end of i+1(j) <= act_cnt-1
            acts[j].state = true;
            i = j;//update i = j
        }else{
            acts[j].state = false;
        }
    }
    cout << endl;
    for (int i = 0; i < act_cnt; i++)
    {
        if(acts[i].state == true){
            cout << i+1 << ' ';
        }
    }
    cout<<"节目的选取情况：";
	for(int i=0;i<act_cnt;i++)
	cout<<acts[i].state<<"    "; 
    return 0;
}












