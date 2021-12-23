#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;
char s[maxn + 10];

int dp(int i, int j)
{
    if(i >= j) return 0;
    int ans = -1;
    if(ans >= 0) return ans;
    if(s[i] == s[j]) return ans = dp(i+1, j-1);
    return ans = min(dp(i+1, j), dp(i, j-1)) + 1;
}

int main()
{
    scanf("%s", s+1);
    int n = strlen(s+1);
    cout << dp(1, n);
    return 0;
}
