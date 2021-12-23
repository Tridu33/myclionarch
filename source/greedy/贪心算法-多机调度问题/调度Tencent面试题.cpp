#include<iostream>
#include<algorithm>
#include<vector>
/*
有n个机器，m个任务，1<=n,m<=100000，每个机器都有工作时间的最大限制0< xi<1000和完成的最大难度0<=yi<=100，每个任务也有所需要的时间和难度，
 只要机器的时间大于等于任务，难度大于等于任务，该任务就可以被机器完成，
 每完成一个任务就可以得到200*xi+3*yi的money，问最多能有多少个任务被完成，
 并且保证完成任务数量最多的情况下，所得到的money最多是多少？

解法：贪心算法，根据公式200*xi+3*yi可知，尽可能的将机器去执行xi较大的任务，可以获得更多的money。
第一步：将机器和任务都按照工作时间xi排序，如果xi相同则按照yi排序。（逆序）
第二部：用任务的时间来找到所有符合条件的机械，再从中找到最接近任务等级的机械，即可。如果你找到比任务x，y大的机械就直接计算的话，就会出错。（如果这点想不通的话，你可以想一下，下面这组数据）：
2 2
150 5
102 2
100 3
101 1
*/
using namespace std;
struct node {
    int x, y;
};
bool compare(node a, node b) {
    if (a.x == b.x)
        return a.y > b.y;
    else
        return a.x > b.x;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<node> machine(n);
    vector<node> task(m);
    for (int i = 0; i < n; i++)
        cin >> machine[i].x >> machine[i].y;
    for (int j = 0; j < m; j++)
        cin >> task[j].x >> task[j].y;
    sort(machine.begin(), machine.end(), compare);
    sort(task.begin(), task.end(), compare);
    int ans = 0, sum = 0;
    int temp[100];
    for (int i = 0, j = 0; i < task.size(); i++) {
        while (j <machine.size() && machine[j].x >= task[i].x) {
            temp[machine[j].y]++;
            j++;
        }
        for (int k = task[i].y; k <= 100; k++) {
            if (temp[k]) {
                ans += 200 * task[i].x + 3 * task[i].y;
                sum++;
                temp[k]--;
                break;
            }
        }
    }
    cout << sum<< " "<<ans;
    system("pause");
    return 0;
}