#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> path; // 符合条件的结果
    // n ：目标和，也就是题目中的n。
    // k：题目中要求k个数的集合。
    // sum：已经收集的元素的总和，也就是path里元素的总和。
    // startIndex：下一层for循环搜索的起始位置。
    vector<vector<int>> res;
    void backtrack(vector<int> nums, int n, int k,int startIndex){
        if(path.size() == k){
            int sum = 0;
            for(auto x: path) sum += x;
            if(sum == n){
                res.push_back(path);
            }
            for(int i = startIndex;i<nums.size();i++){
                path.push_back(nums[i]);
                backtrack(nums, n, k, i+1);
                path.pop_back();
            }
            return ;
        }
        return ;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        res.clear();
        path.clear();
        backtrack(nums, n,k,0);
        return res;
    }
};

int main(){
    int k,n;
    cin >> k >> n;
    Solution sol;
    vector<vector<int>> ans = sol.combinationSum3(k,n);
    for(auto x : ans){
        for(int x_i : x){
            cout << x_i << ',';
        }
        cout << endl;
    }
}