//钢条切割问题
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int* record;//记录数组，避免重复子问题的多次计算
int* steel;//钢条价格表，下标对应钢条长度
int steel_len;//钢条原始长度，也是钢条种类的数量

//直接递归，性能很差，因为有很多的重复子问题多次计算
int dfs(int len) {
	if (len == 0) return 0;
	int max_value = steel[len];
	//确定首段长度，剩下的递归
	for (int first_len = 1; first_len <= len - 1; first_len++) {
		int v = steel[first_len] + dfs(len - first_len);
		max_value = max(v, max_value);
	}
	return max_value;
}

//记忆型递归，解决了重复子问题多次计算
int dfs_2(int len) {
	if (len == 0) return 0;
	int v;
	int max_value = steel[len];
	//计算前查询
	if (record[len] >= 0) {
		return record[len];
	}
	//确定首段长度，剩下的递归
	for (int first_len = 1; first_len <= len - 1; first_len++) {
		v = steel[first_len] + dfs_2(len - first_len);
		max_value = max(v, max_value);
	}
	//计算后保存
	record[len] = max_value;
	return max_value;
}


//动规解法
int dp(int len) {
	int* arr_dp = new int[len + 1];
	memset(arr_dp, 0, (len + 1) * sizeof(int));//初始化为0
	//对于dp表的每一项（钢条总长度）
	for (int i = 1; i <= len; i++) {
		//首段长度j
		for (int j = 1; j <= i; j++) {
			arr_dp[i] = max(arr_dp[i], steel[j] + arr_dp[i - j]);
		}
	}
	return arr_dp[len];
}

int main() {
	cin >> steel_len;
	steel = new int[steel_len + 1];
	steel[0] = 0;
	for (int i = 1; i <= steel_len; ++i) {
		cin >> steel[i];
	}
	record = new int[steel_len + 1];
	memset(record, -1, (steel_len + 1) * sizeof(int));
	cout << dfs(steel_len) << endl;
	cout << dfs_2(steel_len) << endl;
	cout << dp(steel_len) << endl;
	return 0;
}

/* 测试用例： 10 1 5 8 16 10 17 17 20 24 30 */
















#include"bits/stdc++.h"
using namespace std;

class Solution{
private:

public:
    int cutting(vector<int>&F,int n)
    {
        vector<int> dp(n+1,0);
        for (int i = 1; i <= n;i++)
        {
            int q = -1;
            for (int i = 1; i <= n;i++)
            {
                int q = -1;
                for (int j = 1; j <= i;j++)
                {
                    q = max(q,F[j-1] + dp[i-j]);
                };
                dp[i] = q;
            };
        }
        return dp[n];
    };
};

int main (){
    Solution sol;
    vector<int> F = vector<int>{1,2,3,4,5,6,7};
    cout << sol.cutting(F, n) << endl;
    return 0;
}





















































