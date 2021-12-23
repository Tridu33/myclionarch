#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int add(vector<vector<int>> & matrix){
        //
        return matrix.size();
    }
}

int main(){
    int m, n;
    for (int i = 0; i < m;i++)
    {
        for (int j = 0; j < n;j++)
        {
            ;
        }
    }
    string input;
    while(getline(cin,input) ){
        vector<int> nums;
        istringstream iss(input);
        int sum = 0,val;
        while(iss >> val){
            nums.push_back(val);
        }
        Solution sol;
        cout<< sol.add(nums) <<endl;
    }
    return 0;
}











