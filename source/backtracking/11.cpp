

#include <bits/stdc++.h>
using namespace std;
vector<int> path;//{}
int res=0;
void backtrack(vector<int> &nums,int m,int target,int startIndex){
    int sum = 0;for(auto x : path) sum += x;
    if(path.size() == m && sum == target){
        res++;//
        return;
    }
    for(int i = startIndex;i<nums.size();i++){
        path.push_back(nums[i]);
        backtrack(nums, m,target,i+1);//组合
        path.pop_back();
    }
    return;
}
int main(){
    int m,target,n;
    while(cin >> m >> target >> n){
        vector<int> nums(n,0);
        for(int i =0;i<n;i++){
            cin >> nums[i];
        }
        path.clear();
        backtrack(nums,m,target,0);
        cout << res << endl;
    }
    return 0;
}







//#include<bits/stdc++.h>
//using namespace std;
//unordered_set<int> myset;//res
//int sum=0;//path
//void backtrack(const vector<int>& input, int startindex){
//    myset.insert(sum);
//    for(int i = startindex;i<input.size();i++){
//        if(i > startindex && input[i] == input[i-1]) continue;
//        sum += input[i];
//        backtrack(input, 1 + i);
//        sum -= input[i];
//    }
//    return ;
//}
//int main(){
//    int n;
//    while(cin >> n){
//        vector<int> w(n,0),x(n,0);
//        for(int i =0;i<n;i++){
//            cin >> w[i];
//        }
//        for(int i =0; i<n; i++){
//            cin >> x[i];
//        }
//        vector<int> input;
//        for(int i =0;i<w.size();i++){
//            for(int j =0;j<x[i];j++){
//                input.push_back(w[i]);
//            }
//        }
//        sort(input.begin(),input.end());
//        backtrack(input,0);
//        cout << myset.size() << endl;
//        sum = 0;
//        myset.clear();
//    }
//    return 0;
//}
//
//

















//#include<bits/stdc++.h>
//using namespace std;
//class Solution{
//private:
//
//public:
//    int func(vector<int> & nums){
//        return 0;
//    }
//};
//int getlen(string & s,int start,int end){
//    int res = 0;
//    if(start == end){
//        int i = start,j = end; // 奇数
//        res = 1;i--;j++;
//        while(i>=0 && j < s.size() && s[i] == s[j]){
//            i--;j++;
//            res += 2;
//        }
//    }else{
//        if(s[start] == s[end]){
//            res = 2; // 偶数
//            start--; end++;
//            while(start >=0  && end < s.size() && s[start] == s[end]){
//                start--; end++;
//                res += 2;
//            }
//        }else{
//            res = 1;
//        }
//    }
//    return res;
//}
//
//int main(){
//    string str = "ABABACCC'";
////    while(cin >> str){
//        int res = INT_MIN;
//        for(int i = 0; i<str.size(); i++){
//            int l1 = getlen(str,i,i);
//            int l2 = getlen(str,i,i+1);
//            res = max({l1,l2,res});
//        }
//        cout << res << endl;
////    }
//    return 0;
//}