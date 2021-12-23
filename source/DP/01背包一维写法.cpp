#include"bits/stdc++.h"

void test_1_wei_bag_problem(){
    vector<int> weight = {1,3,4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    vector<int> dp(bagweight + 1, 0);

    for (int i = 0; i < weight.size();i++)
    {
        for (int j = bagweight; j >= 0;j--)
        {
            dp[j] = max(dp[j],dp[j - weight[i]] + value[j]);
        };
    }
    cout << dp[bagweight] << endl;
    ;
}


int main(){
    ;
    return 0;
}




















































































