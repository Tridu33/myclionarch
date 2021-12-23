#include<string>
// #include<sstream>
// #include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int add(vector<int> & nums){
        int sum = 0;
        for(auto x: nums){
            sum += x;
        }
        return sum;
    }
};
int main(){
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











