//
// Created by tridu33 on 9/27/2021.
//

#include "quickSortRand.h"
#include <stdlib.h>     /* srand, rand */
using namespace  std;
#include <bits/stdc++.h>
class Solution {
public:
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
    int Random_partition(vector<int> & nums,int l,int r){
        srand((unsigned) time(NULL));
        int i = rand()%nums.size();
        swap(nums[i],nums[r]);
        return partition(nums,l,r);
    }
    void quicksort(vector<int> & nums,int s , int e){
        if(s >= e) return;
        int pivotindex = Random_partition(nums,s,e);
        quicksort(nums,s,pivotindex-1);
        quicksort(nums,pivotindex+1,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        int  n = nums.size();
        quicksort(nums,0,n-1);//快排
        return nums;
    }
};

int main(){
    vector<int> nums = {1,4,3,5,7,9,0,56};
    Solution sol;
    vector<int> vec = sol.sortArray(nums);
    for(auto x: vec){
        cout << x << ' ' << endl;
    }
    return 0;
}