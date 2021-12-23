#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // quicksortArray
    int partition(vector<int> & nums,int l,int r){
        int pivot = nums[r];
        int s = l,e = r-1;
        while(s<=e){
            while(s<=e && nums[s] <= pivot) s++;
            while(s<=e && nums[e] >= pivot) e--;
            if(s <= e) swap(nums[s],nums[e]);
        }
        swap(nums[s],nums[r]);
        return s;
    }
    int randomPartition(vector<int> nums,int l,int r){
        int i = rand()%(r-l+1) + l;
        swap(nums[i],nums[r]);
        return partition(nums,l,r);
    }
    void quicksort(vector<int> & nums,int s , int e){
        if(s >= e) return;
        int pivotindex = randomPartition(nums,s,e);
        quicksort(nums,s,pivotindex-1);
        quicksort(nums,pivotindex+1,e);
    }
    vector<int> quicksortArray(vector<int>& nums) {
        int  n = nums.size();
        quicksort(nums,0,n-1);//快排
        return nums;
    }

    // mergeArray
    ;
    // headArray

};

int main(){
    vector<int> nums;
    int n;
    while(cin >> n){
        nums.push_back(n);
        cin.get();//读取掉数据之间的逗号
        //当读到逗号需要操作：
        //if(cin.get()==','{
        // 操作
        //}
    }
    srand((unsigned ) time(NULL));
    Solution sol;
    sol.quicksortArray(nums);
    for(auto x : nums){
        cout << x << ',';
    }
    return 0;
}