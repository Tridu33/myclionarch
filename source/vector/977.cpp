
/*
 * lc 977
5
-4,-1,0,3,10
 */
#include<bits/stdc++.h>
using namespace  std;class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);
        for (int i = 0, j = A.size() - 1; i <= j;) { // 注意这里要i <= j，因为最后要处理两个元素
            if (A[i] * A[i] < A[j] * A[j])  {
                result[k--] = A[j] * A[j];
                j--;
            }
            else {
                result[k--] = A[i] * A[i];
                i++;
            }
        }
        return result;
    }
};

class Solution1 {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            A[i] *= A[i];
        }
        sort(A.begin(), A.end()); // 快速排序
        return A;
    }
};
void printVector(vector<int> nums){
    int n = nums.size();
    for(int i =0;i<n;i++){
        cout << nums[i] << ' ';
    }
    cout << endl;
}
int main(){
    int n;
    while(cin >> n){
        vector<int> nums(n,-1);
        char ch = ',';
        for(int i =0;i<n;i++){
            cin >> ch;
            if(ch == ','){
                cin >> ch;// next
            }
            nums[i] = ch - '0';
        }
//        cout << endl;
//        for(int i =0;i<n;i++){
//            cout << nums[i] << ' ';
//        }
//        int target ;
//        cin >> target ;
        Solution sol;
        printVector(sol.sortedSquares(nums));
    }
    return 0;
}













