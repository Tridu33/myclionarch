
#include<vector>
#include<iostream>
#include"bits/stdc++.h"
using namespace std;

void test_completePack(){
    vector<int> weight = {1,3,4};
    vector<int> value = {15, 20, 30};

    int bagsize = 4;
    vector<int> dp(bagsize + 1,0);
    for (int i = 0; i < weight.size(); i++)
    {
        for (int j = 0; j < bagsize;j++)
        {
            dp[j] = max(dp[j],dp[j - weight[i]] + value[i]);
        }
    }
    std::cout << dp[bagsize] << endl;
}


void test_completePack2(){
    vector<int> weight = {1,3,4};
    vector<int> value = {15, 20, 30};

    int bagsize = 4;
    vector<int> dp(bagsize + 1,0);
    for (int j = 0; j < bagsize;j++)
    {
        for (int i = 0; i < weight.size(); i++)
        {
            dp[j] = max(dp[j],dp[j - weight[i]] + value[i]);
        }
    }
    std::cout << dp[bagsize] << endl;
}

int main(){
    test_completePack();
}






















































































































