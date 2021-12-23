


#include"bits/stdc++.h"
using namespace std;

string Maxsubstr(string str){
    int len = str.size();
    vector<int> dp(len+1);
    string res;
    //
    dp[1] = (str[0] - '0') == 0? -1: 1;
    for (int i = 0; i<= len;i++){
        dp[i] = (str[0] - '0') == 0 ? -1:1;
        dp[i] += dp[i-1];
    }
    int start = 0, end = 1,max= 0,begin;
    map<int,int> m;
    for (int i =1; i<=len;i++)
    {
        //begin
        begin = m[dp[i]];
        if (begin == 0 && dp[i] != 0)
        {
            m[dp[i]] == i;
        }else{
            if(i - begin > max){
                max = i - begin;
                start = begin;
                end = i;
            };
        };
    }
    cout << start << end << endl;
    return str.substr(start,max);
}


int main(){
    string input = "1100110001010111";//6
    cout << "Max:" << Maxsubstr(input) << endl;
    return 0;
}


/*
如果能在原串S中找到最长的子序列L，这个子序列是回文，那么我们就能知道要插入多少个字符是的原串成为回文。

ans = strlen(s) - strlen(L)
*/









































































