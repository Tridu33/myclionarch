
/*
 * lc 704
6
-1 0 3 5 9 12
9
 */
#include<bits/stdc++.h>
using namespace  std;
int search1(vector<int> & nums,int & target){
    int left = 0;
    int right = nums.size()-1;
    // [left,right]
    while(left <= right){
        int mid = left + ((right - left)>>1);
        // int mid = left + (right - left)>>1;优先级>>更低
        if(nums[mid] > target){
            right = mid-1;
        }else if(nums[mid] < target){
            left = mid+1;
        }else {// ==
            return mid;
        }
    }
    return -1;
}
int search2(vector<int> & nums,int & target){
    int left = 0;
    int right = nums.size()-1;
    // [left,right)
    while(left < right){
        int mid = left + ((right - left)>>1);
        // int mid = left + (right - left)>>1;优先级>>更低
        if(nums[mid] > target){
            right = mid;
        }else if(nums[mid] < target){
            left = mid+1;
        }else {// ==
            return mid;
        }
    }
    return -1;
}
int main(){
    int n;
    while(cin >> n){
        vector<int> nums(n,-1);
        for(int i =0;i<n;i++){
            cin >> nums[i];
        }
//        cout << endl;
//        for(int i =0;i<n;i++){
//            cout << nums[i] << ' ';
//        }
        int target ;
        cin >> target ;
        cout << search1(nums,target) << endl;
    }
    return 0;
}













