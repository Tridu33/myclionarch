#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    const int N = 6;                     //物品个数
    const int V = 10;                    //背包体积
    int C[N + 1] = { -1,5,6,5,1,19,7 };  //第i个物品的体积（下标从1开始）
    int W[N + 1] = { -1,2,3,1,4,6,5 };   //第i个物品的价值
    int F[N + 1][V + 1] = { 0 };         //状态

    for (int i = 1; i <= N; i++)  //对于第i个物品
        for (int v = 0; v <= V; v++)
        {
            F[i][v] = F[i - 1][v];  //第i个不放
            if (v - C[i] >= 0 && F[i][v] < F[i - 1][v - C[i]] + W[i])  //如果比它大，再放第i个
                F[i][v] = F[i - 1][v - C[i]] + W[i];
        }

    cout << "最大价值是：" << F[N][V] << endl;  //9

    return 0;
}


// 1 dimension
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    const int N = 6;                     //物品个数
    const int V = 10;                    //背包体积
    int C[N + 1] = { -1,5,6,5,1,19,7 };  //第i个物品的体积（下标从1开始）
    int W[N + 1] = { -1,2,3,1,4,6,5 };   //第i个物品的价值
    int F[V + 1] = { 0 };                //状态

    for (int i = 1; i <= N; i++)  //对于第i个物品
        for (int v = V; v >= C[i]; v--)
            F[v] = max(F[v], F[v - C[i]] + W[i]);
        
    cout << "最大价值是：" << F[V] << endl;  //9

    return 0;
}














void test_2_wei_bag_problem1() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // 二维数组
    vector<vector<int>> dp(weight.size() + 1, vector<int>(bagWeight + 1, 0));

    // 初始化
    for (int j = weight[0]; j <= bagWeight; j++) {
        dp[0][j] = value[0];
    }

    // weight数组的大小 就是物品个数
    for(int i = 1; i < weight.size(); i++) { // 遍历物品
        for(int j = 0; j <= bagWeight; j++) { // 遍历背包容量
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);

        }
    }

    cout << dp[weight.size() - 1][bagWeight] << endl;
}

int main() {
    test_2_wei_bag_problem1();
}



#include<vector>
void test_1_wei_bag_problem(){
  vector<int> weight = {1, 3, 4};
  vector<int> value = {15,20,30};
  int bagweight;
  
  vector<int> dp(bagweight+1,0);
  for (int i = 0; i < weight;){
    for (int j = 0;)
    {
      ;
    };
  };
}





















function testWeightBagProblem (wight, value, size) {
  const len = wight.length, 
    dp = Array.from({length: len + 1}).map(
      () => Array(size + 1).fill(0)
    );
  
  for(let i = 1; i <= len; i++) {
    for(let j = 0; j <= size; j++) {
      if(wight[i - 1] <= j) {
        dp[i][j] = Math.max(
          dp[i - 1][j], 
          value[i - 1] + dp[i - 1][j - wight[i - 1]]
        )
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

//   console.table(dp);

  return dp[len][size];
}

function testWeightBagProblem2 (wight, value, size) {
  const len = wight.length, 
    dp = Array(size + 1).fill(0);
  for(let i = 1; i <= len; i++) {
    for(let j = size; j >= wight[i - 1]; j--) {
      dp[j] = Math.max(dp[j], value[i - 1] + dp[j - wight[i - 1]]);
    }
  }
  return dp[size];
}


function test () {
  console.log(testWeightBagProblem([1, 3, 4, 5], [15, 20, 30, 55], 6));
}

test();













