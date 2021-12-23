#include<bits/stdc++.h>
using namespace std;
bool ifIn(vector<int> cur,int n){
    for(auto x: cur){
        if(x == n) return true;
    }
    return false;
}
int main(){
    int n;
    int res = 0;
    vector<int> current_used(3,0);
    vector<int> nums;
    while(cin >> n){
        nums.push_back(n);
    }
    long counter = 0;
    for(int i =0;i<nums.size();i++){
        res += 15;
        if(ifIn(current_used,nums[i]) == false){
            current_used[counter%3] = nums[i];
            counter++;
            if(ifIn(current_used,0) == false)
                res += 6;//前三个去重不需要+6
        }
    }
    cout << res << endl;
    return 0;
}